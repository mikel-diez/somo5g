/*
 *
 * Copyright 2021-2023 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#pragma once

#include "srsran/du/du_test_config.h"
#include "srsran/mac/mac.h"

namespace srsran {

class mac_test_mode_adapter final : public mac_interface,
                                    public mac_ue_control_information_handler,
                                    public mac_ue_configurator
{
public:
  explicit mac_test_mode_adapter(std::unique_ptr<mac_interface>                mac_ptr,
                                 const srs_du::du_test_config::test_ue_config& test_ue_cfg);
  ~mac_test_mode_adapter() override;

  mac_cell_rach_handler& get_rach_handler(du_cell_index_t cell_index) override
  {
    return mac_adapted->get_rach_handler(cell_index);
  }

  mac_cell_slot_handler& get_slot_handler(du_cell_index_t cell_index) override
  {
    return mac_adapted->get_slot_handler(cell_index);
  }

  mac_cell_manager& get_cell_manager() override { return mac_adapted->get_cell_manager(); }

  mac_ue_control_information_handler& get_ue_control_info_handler() override { return *this; }

  mac_pdu_handler& get_pdu_handler(du_cell_index_t cell_index) override
  {
    return mac_adapted->get_pdu_handler(cell_index);
  }

  mac_paging_information_handler& get_cell_paging_info_handler() override
  {
    return mac_adapted->get_cell_paging_info_handler();
  }

  mac_ue_configurator& get_ue_configurator() override { return *this; }

  mac_cell_control_information_handler& get_control_info_handler(du_cell_index_t cell_index) override;

private:
  void handle_dl_buffer_state_update_required(const mac_dl_buffer_state_indication_message& dl_bs) override;

  // mac_ue_configurator interface.
  async_task<mac_ue_create_response_message>
  handle_ue_create_request(const mac_ue_create_request_message& cfg) override;
  async_task<mac_ue_reconfiguration_response_message>
  handle_ue_reconfiguration_request(const mac_ue_reconfiguration_request_message& cfg) override;
  async_task<mac_ue_delete_response_message>
       handle_ue_delete_request(const mac_ue_delete_request_message& cfg) override;
  void handle_ul_ccch_msg(du_ue_index_t ue_index, byte_buffer pdu) override;

  std::vector<mac_logical_channel_config> adapt_bearers(const std::vector<mac_logical_channel_config>& orig_bearers);

  srs_du::du_test_config::test_ue_config test_ue;

  std::unique_ptr<mac_interface> mac_adapted;

  std::vector<std::unique_ptr<mac_cell_control_information_handler>> cell_info_handler;

  du_ue_index_t test_ue_index = INVALID_DU_UE_INDEX;
};

} // namespace srsran