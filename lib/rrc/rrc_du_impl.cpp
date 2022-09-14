/*
 *
 * Copyright 2013-2022 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#include "rrc_du_impl.h"
#include "../ran/gnb_format.h"

using namespace srsgnb;
using namespace srs_cu_cp;
using namespace asn1::rrc_nr;

rrc_du_impl::rrc_du_impl(const rrc_cfg_t&              cfg_,
                         rrc_ue_du_processor_notifier& rrc_ue_du_proc_notif_,
                         rrc_ue_nas_notifier&          nas_notif_) :
  cfg(cfg_), rrc_ue_du_proc_notifier(rrc_ue_du_proc_notif_), nas_notifier(nas_notif_)
{
}

rrc_ue_interface* rrc_du_impl::add_ue(rrc_ue_creation_message msg)
{
  if (ue_db.contains(msg.ue_index)) {
    // UE already exists with same ue_index
    return nullptr;
  }

  // TODO: check if du_to_cu_container is valid, reject if not

  // create UE object
  ue_index_t ue_index = msg.ue_index;
  ue_db.emplace(ue_index,
                std::make_unique<rrc_ue_impl>(*this,
                                              rrc_ue_du_proc_notifier,
                                              nas_notifier,
                                              msg.ue_index,
                                              msg.c_rnti,
                                              msg.cgi,
                                              cfg.ue_default_cfg,
                                              msg.srbs,
                                              msg.du_to_cu_container,
                                              *msg.ue_task_sched));
  auto& u = ue_db[ue_index];
  return u.get();
}

void rrc_du_impl::remove_ue(ue_index_t ue_index)
{
  ue_db.erase(ue_index);
}

void rrc_du_impl::release_ues()
{
  // release all UEs connected to this RRC entity
}

int rrc_du_impl::get_pucch_resources()
{
  // TODO: add proper allocation, return success for now
  return 1;
}

bool rrc_du_impl::is_rrc_connect_allowed()
{
  return !reject_users;
}

void rrc_du_impl::handle_amf_connection()
{
  reject_users = false;
}

void rrc_du_impl::handle_amf_connection_drop()
{
  reject_users = true;
}