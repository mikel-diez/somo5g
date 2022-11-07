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

// This file was generated using the following MATLAB class on 07-Nov-2022:
//   + "srsPUSCHDemodulatorUnittest.m"

#include "../../support/resource_grid_test_doubles.h"
#include "srsgnb/phy/upper/channel_processors/pusch_demodulator.h"
#include "srsgnb/support/file_vector.h"

namespace srsgnb {

struct context_t {
  float                            noise_var;
  pusch_demodulator::configuration config;
};

struct test_case_t {
  context_t                                               context;
  file_vector<resource_grid_reader_spy::expected_entry_t> symbols;
  file_vector<cf_t>                                       estimates;
  file_vector<log_likelihood_ratio>                       sch_data;
};

static const std::vector<test_case_t> pusch_demodulator_test_data = {
    // clang-format off
  {{0.0084369, {8323, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 0, 14, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 821, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols0.dat"}, {"test_data/pusch_demodulator_test_input_estimates0.dat"}, {"test_data/pusch_demodulator_test_output0.dat"}},
  {{0.0053469, {61595, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 262, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols2.dat"}, {"test_data/pusch_demodulator_test_input_estimates2.dat"}, {"test_data/pusch_demodulator_test_output2.dat"}},
  {{0.0052367, {42481, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 324, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols4.dat"}, {"test_data/pusch_demodulator_test_input_estimates4.dat"}, {"test_data/pusch_demodulator_test_output4.dat"}},
  {{0.0055128, {64928, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 77, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols6.dat"}, {"test_data/pusch_demodulator_test_input_estimates6.dat"}, {"test_data/pusch_demodulator_test_output6.dat"}},
  {{0.0049383, {34389, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 2, 10, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 707, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols8.dat"}, {"test_data/pusch_demodulator_test_input_estimates8.dat"}, {"test_data/pusch_demodulator_test_output8.dat"}},
  {{0.0042766, {17549, {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 2, 10, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 838, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols10.dat"}, {"test_data/pusch_demodulator_test_input_estimates10.dat"}, {"test_data/pusch_demodulator_test_output10.dat"}},
  {{0.0053473, {28517, {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 0, 14, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 681, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols12.dat"}, {"test_data/pusch_demodulator_test_input_estimates12.dat"}, {"test_data/pusch_demodulator_test_output12.dat"}},
  {{0.00321, {35807, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 377, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols14.dat"}, {"test_data/pusch_demodulator_test_input_estimates14.dat"}, {"test_data/pusch_demodulator_test_output14.dat"}},
  {{0.0039731, {32335, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 19, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols16.dat"}, {"test_data/pusch_demodulator_test_input_estimates16.dat"}, {"test_data/pusch_demodulator_test_output16.dat"}},
  {{0.0074149, {57914, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 231, 1, {1, 101, 201, 301, 401, 501, 601, 701, 801, 901, 1001}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols18.dat"}, {"test_data/pusch_demodulator_test_input_estimates18.dat"}, {"test_data/pusch_demodulator_test_output18.dat"}},
  {{0.0061506, {10797, {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 935, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols20.dat"}, {"test_data/pusch_demodulator_test_input_estimates20.dat"}, {"test_data/pusch_demodulator_test_output20.dat"}},
  {{0.0052508, {7308, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 28, 1, {1, 101, 201, 301, 401, 501, 601, 701}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols22.dat"}, {"test_data/pusch_demodulator_test_input_estimates22.dat"}, {"test_data/pusch_demodulator_test_output22.dat"}},
  {{0.00017921, {37819, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 242, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols24.dat"}, {"test_data/pusch_demodulator_test_input_estimates24.dat"}, {"test_data/pusch_demodulator_test_output24.dat"}},
  {{0.0014483, {23620, {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 653, 1, {1, 101, 201, 301, 401, 501, 601}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols26.dat"}, {"test_data/pusch_demodulator_test_input_estimates26.dat"}, {"test_data/pusch_demodulator_test_output26.dat"}},
  {{0.0029713, {36848, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 873, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols28.dat"}, {"test_data/pusch_demodulator_test_input_estimates28.dat"}, {"test_data/pusch_demodulator_test_output28.dat"}},
  {{0.002203, {35194, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 825, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201, 1301, 1401, 1501, 1601, 1701, 1801, 1901, 2001}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols30.dat"}, {"test_data/pusch_demodulator_test_input_estimates30.dat"}, {"test_data/pusch_demodulator_test_output30.dat"}},
  {{0.0006493, {37077, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 523, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols32.dat"}, {"test_data/pusch_demodulator_test_input_estimates32.dat"}, {"test_data/pusch_demodulator_test_output32.dat"}},
  {{0.0056883, {7938, {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 214, 1, {1, 101, 201, 301, 401}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols34.dat"}, {"test_data/pusch_demodulator_test_input_estimates34.dat"}, {"test_data/pusch_demodulator_test_output34.dat"}},
  {{0.00026398, {31895, {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 583, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols36.dat"}, {"test_data/pusch_demodulator_test_input_estimates36.dat"}, {"test_data/pusch_demodulator_test_output36.dat"}},
  {{0.0097642, {30384, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 535, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201, 1301, 1401, 1501, 1601, 1701}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols38.dat"}, {"test_data/pusch_demodulator_test_input_estimates38.dat"}, {"test_data/pusch_demodulator_test_output38.dat"}},
  {{0.0015108, {1458, {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 925, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols40.dat"}, {"test_data/pusch_demodulator_test_input_estimates40.dat"}, {"test_data/pusch_demodulator_test_output40.dat"}},
  {{0.0029224, {27424, {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 344, 1, {1, 101, 201, 301, 401}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols42.dat"}, {"test_data/pusch_demodulator_test_input_estimates42.dat"}, {"test_data/pusch_demodulator_test_output42.dat"}},
  {{0.0088019, {63559, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 2, 10, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 328, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols44.dat"}, {"test_data/pusch_demodulator_test_input_estimates44.dat"}, {"test_data/pusch_demodulator_test_output44.dat"}},
  {{0.0050493, {2567, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 744, 1, {1, 101, 201, 301, 401, 501, 601, 701, 801}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols46.dat"}, {"test_data/pusch_demodulator_test_input_estimates46.dat"}, {"test_data/pusch_demodulator_test_output46.dat"}},
  {{0.0023303, {52281, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 0, 14, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 748, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols48.dat"}, {"test_data/pusch_demodulator_test_input_estimates48.dat"}, {"test_data/pusch_demodulator_test_output48.dat"}},
  {{0.0046258, {53944, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 7, 1, {1, 101}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols50.dat"}, {"test_data/pusch_demodulator_test_input_estimates50.dat"}, {"test_data/pusch_demodulator_test_output50.dat"}},
  {{0.0039325, {54267, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 335, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols52.dat"}, {"test_data/pusch_demodulator_test_input_estimates52.dat"}, {"test_data/pusch_demodulator_test_output52.dat"}},
  {{0.0050752, {28177, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 198, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201, 1301, 1401, 1501, 1601, 1701}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols54.dat"}, {"test_data/pusch_demodulator_test_input_estimates54.dat"}, {"test_data/pusch_demodulator_test_output54.dat"}},
  {{0.0055593, {17434, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 997, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols56.dat"}, {"test_data/pusch_demodulator_test_input_estimates56.dat"}, {"test_data/pusch_demodulator_test_output56.dat"}},
  {{0.0034194, {36965, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 2, 10, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 775, 1, {1, 101, 201, 301, 401, 501, 601, 701}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols58.dat"}, {"test_data/pusch_demodulator_test_input_estimates58.dat"}, {"test_data/pusch_demodulator_test_output58.dat"}},
  {{0.0073098, {16131, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 3, 759, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols60.dat"}, {"test_data/pusch_demodulator_test_input_estimates60.dat"}, {"test_data/pusch_demodulator_test_output60.dat"}},
  {{0.0090598, {21363, {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 667, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols62.dat"}, {"test_data/pusch_demodulator_test_input_estimates62.dat"}, {"test_data/pusch_demodulator_test_output62.dat"}},
  {{0.0072248, {38991, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 666, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols64.dat"}, {"test_data/pusch_demodulator_test_input_estimates64.dat"}, {"test_data/pusch_demodulator_test_output64.dat"}},
  {{0.0061761, {62425, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 3, 402, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols66.dat"}, {"test_data/pusch_demodulator_test_input_estimates66.dat"}, {"test_data/pusch_demodulator_test_output66.dat"}},
  {{0.0018544, {58498, {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 2, 10, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 3, 917, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols68.dat"}, {"test_data/pusch_demodulator_test_input_estimates68.dat"}, {"test_data/pusch_demodulator_test_output68.dat"}},
  {{0.0060446, {19039, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::PI_2_BPSK, 2, 10, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 1, 87, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols70.dat"}, {"test_data/pusch_demodulator_test_input_estimates70.dat"}, {"test_data/pusch_demodulator_test_output70.dat"}},
  {{0.0066758, {2620, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 571, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols72.dat"}, {"test_data/pusch_demodulator_test_input_estimates72.dat"}, {"test_data/pusch_demodulator_test_output72.dat"}},
  {{0.008332, {15028, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 452, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols74.dat"}, {"test_data/pusch_demodulator_test_input_estimates74.dat"}, {"test_data/pusch_demodulator_test_output74.dat"}},
  {{0.0044441, {5469, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 3, 876, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols76.dat"}, {"test_data/pusch_demodulator_test_input_estimates76.dat"}, {"test_data/pusch_demodulator_test_output76.dat"}},
  {{0.0028186, {23915, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 79, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201, 1301, 1401, 1501, 1601, 1701, 1801}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols78.dat"}, {"test_data/pusch_demodulator_test_input_estimates78.dat"}, {"test_data/pusch_demodulator_test_output78.dat"}},
  {{0.0080426, {9975, {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 896, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols80.dat"}, {"test_data/pusch_demodulator_test_input_estimates80.dat"}, {"test_data/pusch_demodulator_test_output80.dat"}},
  {{0.0068411, {57664, {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QPSK, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 1, 25, 1, {1, 101, 201, 301}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols82.dat"}, {"test_data/pusch_demodulator_test_input_estimates82.dat"}, {"test_data/pusch_demodulator_test_output82.dat"}},
  {{0.00063626, {54622, {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 3, 986, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols84.dat"}, {"test_data/pusch_demodulator_test_input_estimates84.dat"}, {"test_data/pusch_demodulator_test_output84.dat"}},
  {{0.0080531, {1844, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 361, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols86.dat"}, {"test_data/pusch_demodulator_test_input_estimates86.dat"}, {"test_data/pusch_demodulator_test_output86.dat"}},
  {{0.0046544, {46021, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 1, 293, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols88.dat"}, {"test_data/pusch_demodulator_test_input_estimates88.dat"}, {"test_data/pusch_demodulator_test_output88.dat"}},
  {{0.0094539, {15922, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 1, 289, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201, 1301, 1401, 1501, 1601, 1701, 1801, 1901}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols90.dat"}, {"test_data/pusch_demodulator_test_input_estimates90.dat"}, {"test_data/pusch_demodulator_test_output90.dat"}},
  {{0.0084417, {15147, {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 2, 10, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 3, 201, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols92.dat"}, {"test_data/pusch_demodulator_test_input_estimates92.dat"}, {"test_data/pusch_demodulator_test_output92.dat"}},
  {{0.0013492, {53511, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM16, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 3, 262, 1, {1, 101, 201, 301, 401, 501, 601, 701}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols94.dat"}, {"test_data/pusch_demodulator_test_input_estimates94.dat"}, {"test_data/pusch_demodulator_test_output94.dat"}},
  {{0.0094277, {60352, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 218, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols96.dat"}, {"test_data/pusch_demodulator_test_input_estimates96.dat"}, {"test_data/pusch_demodulator_test_output96.dat"}},
  {{0.0083684, {1899, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 1, 273, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201, 1301, 1401, 1501, 1601}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols98.dat"}, {"test_data/pusch_demodulator_test_input_estimates98.dat"}, {"test_data/pusch_demodulator_test_output98.dat"}},
  {{0.0021725, {54769, {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 1, 586, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols100.dat"}, {"test_data/pusch_demodulator_test_input_estimates100.dat"}, {"test_data/pusch_demodulator_test_output100.dat"}},
  {{0.0055681, {1170, {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 101, 1, {1, 101, 201, 301, 401, 501, 601}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols102.dat"}, {"test_data/pusch_demodulator_test_input_estimates102.dat"}, {"test_data/pusch_demodulator_test_output102.dat"}},
  {{0.00056347, {28299, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 2, 10, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 3, 370, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols104.dat"}, {"test_data/pusch_demodulator_test_input_estimates104.dat"}, {"test_data/pusch_demodulator_test_output104.dat"}},
  {{0.0076368, {6569, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM64, 2, 10, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 1, 920, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201, 1301}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols106.dat"}, {"test_data/pusch_demodulator_test_input_estimates106.dat"}, {"test_data/pusch_demodulator_test_output106.dat"}},
  {{0.0095347, {59721, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 820, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols108.dat"}, {"test_data/pusch_demodulator_test_input_estimates108.dat"}, {"test_data/pusch_demodulator_test_output108.dat"}},
  {{0.0097399, {11894, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 174, 1, {1, 101, 201, 301, 401, 501, 601}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols110.dat"}, {"test_data/pusch_demodulator_test_input_estimates110.dat"}, {"test_data/pusch_demodulator_test_output110.dat"}},
  {{0.009178, {40052, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 1, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 1, 26, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols112.dat"}, {"test_data/pusch_demodulator_test_input_estimates112.dat"}, {"test_data/pusch_demodulator_test_output112.dat"}},
  {{0.0024414, {9920, {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 228, 1, {1, 101, 201, 301, 401, 501, 601}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols114.dat"}, {"test_data/pusch_demodulator_test_input_estimates114.dat"}, {"test_data/pusch_demodulator_test_output114.dat"}},
  {{0.0076738, {16457, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 1, 307, 1, {}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols116.dat"}, {"test_data/pusch_demodulator_test_input_estimates116.dat"}, {"test_data/pusch_demodulator_test_output116.dat"}},
  {{0.00032761, {55208, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, modulation_scheme::QAM256, 2, 10, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 895, 1, {1,  101,  201,  301,  401,  501,  601,  701,  801,  901, 1001, 1101, 1201}, {0}}}, {"test_data/pusch_demodulator_test_input_symbols118.dat"}, {"test_data/pusch_demodulator_test_input_estimates118.dat"}, {"test_data/pusch_demodulator_test_output118.dat"}},
    // clang-format on
};

} // namespace srsgnb
