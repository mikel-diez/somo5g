/*
 *
 * Copyright 2021-2023 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#include "du_stop_procedure.h"
#include "srsran/support/async/async_timer.h"
#include "srsran/support/async/execute_on.h"

using namespace srsran;
using namespace srs_du;

du_stop_procedure::du_stop_procedure(du_ue_manager& ue_mng_) :
  ue_mng(ue_mng_), proc_logger(srslog::fetch_basic_logger("DU-MNG"), "DU Stop")
{
}

void du_stop_procedure::operator()(coro_context<async_task<void>>& ctx)
{
  CORO_BEGIN(ctx);

  proc_logger.log_proc_started();

  // TODO: Call F1 Removal Request if not yet called.

  // Forcefully interrupt all UE activity.
  CORO_AWAIT(ue_mng.stop());

  proc_logger.log_proc_completed();

  CORO_RETURN();
}