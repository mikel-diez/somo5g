/*
 *
 * Copyright 2013-2022 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#pragma once

#include "rrc_cell_context.h"
#include "srsgnb/adt/byte_buffer.h"
#include "srsgnb/adt/optional.h"
#include "srsgnb/asn1/rrc_nr/rrc_nr.h"
#include "srsgnb/rrc/rrc.h"
#include "srsgnb/security/security.h"
#include "srsgnb/support/async/async_task.h"
#include "srsgnb/support/timers.h"

namespace srsgnb {

namespace srs_cu_cp {

struct rrc_pdu_message {
  rrc_pdu_message(byte_buffer_slice pdu_) : pdu(std::move(pdu_)) {}
  byte_buffer_slice pdu;
};

/// Interface to notify about a new SRB PDU.
class rrc_pdu_notifier
{
public:
  virtual ~rrc_pdu_notifier() = default;

  /// \brief Notify about a new PDU.
  /// \param[in] msg The RRC PDU message.
  virtual void on_new_pdu(const rrc_pdu_message& msg) = 0;
};

/// Interface to configure security in a SRB
/// TX PDCP entity.
class rrc_tx_security_notifier
{
public:
  virtual ~rrc_tx_security_notifier() = default;

  virtual void set_as_security_config(security::sec_128_as_config sec_cfg)                                       = 0;
  virtual void enable_or_disable_security(security::integrity_enabled integ, security::ciphering_enabled cipher) = 0;
};

/// Interface to configure security in a SRB.
/// RX PDCP entity.
class rrc_rx_security_notifier
{
public:
  virtual ~rrc_rx_security_notifier() = default;

  virtual void set_as_security_config(security::sec_128_as_config sec_cfg)                                       = 0;
  virtual void enable_or_disable_security(security::integrity_enabled integ, security::ciphering_enabled cipher) = 0;
};

/// Struct to hold notifiers for a specific SRB
struct srb_notifiers {
  rrc_pdu_notifier*         pdu_notifier    = nullptr;
  rrc_tx_security_notifier* tx_sec_notifier = nullptr;
  rrc_rx_security_notifier* rx_sec_notifier = nullptr;
};

/// Non-owning handlers to PDU notifiers.
using srb_notifiers_array = std::array<srb_notifiers, MAX_NOF_SRBS>;

/// Dummy notifier that just logs the PDU.
/// An object of this type is instantiated upon creation of the SRB context to avoid nullptr checks.
class rrc_pdu_null_notifier : public rrc_pdu_notifier
{
public:
  rrc_pdu_null_notifier() = default;
  void on_new_pdu(const rrc_pdu_message& msg) override
  {
    srsgnb_assertion_failure("Received PDU on unconnected notifier. Discarding.");
    logger.error("Received PDU on unconnected notifier. Discarding.");
  };

private:
  srslog::basic_logger& logger = srslog::fetch_basic_logger("RRC");
};

/// Interface used by the RRC Setup procedure to notifiy the RRC UE.
class rrc_ue_setup_proc_notifier
{
public:
  rrc_ue_setup_proc_notifier()          = default;
  virtual ~rrc_ue_setup_proc_notifier() = default;

  /// \brief Notify about a DL CCCH message.
  /// \param[in] dl_ccch_msg The DL CCCH message.
  virtual void on_new_dl_ccch(const asn1::rrc_nr::dl_ccch_msg_s& dl_ccch_msg) = 0;

  /// \brief Notify about the need to delete a UE.
  virtual void on_ue_delete_request() = 0;
};

struct srb_creation_message {
  ue_index_t               ue_index;
  srb_id_t                 srb_id;
  asn1::rrc_nr::pdcp_cfg_s pdcp_cfg;
};

/// Interface used by the RRC security mode procedure
/// to notify the RRC UE of the security mode context update.
class rrc_ue_security_mode_command_proc_notifier
{
public:
  rrc_ue_security_mode_command_proc_notifier()          = default;
  virtual ~rrc_ue_security_mode_command_proc_notifier() = default;

  /// \brief Notify about a DL DCCH message.
  /// \param[in] dl_ccch_msg The DL DCCH message.
  virtual void on_new_dl_dcch(const asn1::rrc_nr::dl_dcch_msg_s& dl_dcch_msg) = 0;

  /// \brief Notify about the need to delete a UE.
  virtual void on_ue_delete_request() = 0;

  /// \brief Setup security in the UE. This includes storing the K_gNB,
  /// the AS keys, and configuring the PDCP entity security on SRB1
  virtual void on_new_security_config(security::sec_as_config sec_cfg) = 0;
};

/// Interface to notify about RRC UE Context messages.
class rrc_ue_du_processor_notifier
{
public:
  virtual ~rrc_ue_du_processor_notifier() = default;

  /// \brief Notify about the need to create an SRB.
  /// \param[in] msg The SRB creation message.
  virtual void on_create_srb(const srb_creation_message& msg) = 0;

  /// \brief Notify about a UE Context Release Command.
  /// \param[in] msg The UE Context Release Command message.
  virtual void on_ue_context_release_command(const ue_context_release_command_message& msg) = 0;
};

/// Schedules asynchronous tasks associated with an UE.
class rrc_ue_task_scheduler
{
public:
  virtual ~rrc_ue_task_scheduler()                                    = default;
  virtual void           schedule_async_task(async_task<void>&& task) = 0;
  virtual unique_timer   make_unique_timer()                          = 0;
  virtual timer_manager& get_timer_manager()                          = 0;
};

struct initial_ue_message {
  ue_index_t                             ue_index;
  byte_buffer                            nas_pdu;
  rrc_cell_context                       cell;
  asn1::rrc_nr::establishment_cause_opts establishment_cause;
};

struct ul_nas_transport_message {
  ue_index_t       ue_index;
  byte_buffer      nas_pdu;
  rrc_cell_context cell;
};

struct dl_nas_transport_message {
  byte_buffer nas_pdu;
};

/// Interface to notify about NAS messages.
class rrc_ue_nas_notifier
{
public:
  virtual ~rrc_ue_nas_notifier() = default;

  /// \brief Notify about the Initial UE Message.
  /// \param[in] msg The initial UE message.
  virtual void on_initial_ue_message(const initial_ue_message& msg) = 0;

  /// \brief Notify about an Uplink NAS Transport message.
  /// \param[in] msg The Uplink NAS Transport message.
  virtual void on_ul_nas_transport_message(const ul_nas_transport_message& msg) = 0;
};

struct rrc_reconfiguration_response_message {
  ue_index_t ue_index;
  bool       success;
};

/// Interface to notify about control messages.
class rrc_ue_control_notifier
{
public:
  virtual ~rrc_ue_control_notifier() = default;

  // TODO: Add other control messages
};

/// Handle downlink NAS transport messages.
class rrc_ue_dl_nas_message_handler
{
public:
  virtual ~rrc_ue_dl_nas_message_handler() = default;

  /// \brief Handle the received Downlink NAS Transport message.
  /// \param[in] msg The Downlink NAS Transport message.
  virtual void handle_dl_nas_transport_message(const dl_nas_transport_message& msg) = 0;
};

// Globally unique AMF identifier.
struct guami {
  optional<std::string> plmn;
  uint16_t              amf_set_id;
  uint8_t               amf_pointer;
  uint8_t               amf_region_id;
};

/// Handle control messages.
class rrc_ue_control_message_handler
{
public:
  virtual ~rrc_ue_control_message_handler() = default;

  /// \brief Handle an update of the GUAMI.
  /// \param[in] msg The new GUAMI.
  virtual void handle_new_guami(const guami& msg) = 0;
};

struct rrc_init_security_context {
  security::sec_as_key           k;
  security::supported_algorithms supported_int_algos;
  security::supported_algorithms supported_enc_algos;
};

/// Handler to initialize the security context from NGAP.
class rrc_ue_init_security_context_handler
{
public:
  virtual ~rrc_ue_init_security_context_handler() = default;

  /// \brief Handle the received Downlink NAS Transport message.
  /// \param[in] msg The Downlink NAS Transport message.
  virtual async_task<bool> handle_init_security_context(const rrc_init_security_context& msg) = 0;
};

/// Combined entry point for the RRC UE handling.
/// It will contain getters for the interfaces for the various logical channels handled by RRC.
class rrc_ue_interface : public rrc_ul_ccch_pdu_handler,
                         public rrc_ul_dcch_pdu_handler,
                         public rrc_ue_dl_nas_message_handler,
                         public rrc_ue_control_message_handler,
                         public rrc_ue_init_security_context_handler,
                         public rrc_ue_setup_proc_notifier,
                         public rrc_ue_security_mode_command_proc_notifier
{
public:
  rrc_ue_interface()          = default;
  virtual ~rrc_ue_interface() = default;

  virtual rrc_ul_ccch_pdu_handler& get_ul_ccch_pdu_handler()                              = 0;
  virtual rrc_ul_dcch_pdu_handler& get_ul_dcch_pdu_handler()                              = 0;
  virtual void                     connect_srb_notifier(srb_id_t                  srb_id,
                                                        rrc_pdu_notifier&         notifier,
                                                        rrc_tx_security_notifier* tx_sec,
                                                        rrc_rx_security_notifier* rx_sec) = 0;
};

} // namespace srs_cu_cp

} // namespace srsgnb
