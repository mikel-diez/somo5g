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

#include "pucch_detector.h"
#include "srsgnb/phy/generic_functions/generic_functions_factories.h"
#include "srsgnb/phy/upper/channel_coding/channel_coding_factories.h"
#include "srsgnb/phy/upper/channel_modulation/channel_modulation_factories.h"
#include "srsgnb/phy/upper/channel_processors/pbch_encoder.h"
#include "srsgnb/phy/upper/channel_processors/pbch_modulator.h"
#include "srsgnb/phy/upper/channel_processors/pdcch_encoder.h"
#include "srsgnb/phy/upper/channel_processors/pdcch_modulator.h"
#include "srsgnb/phy/upper/channel_processors/pdcch_processor.h"
#include "srsgnb/phy/upper/channel_processors/pdsch_encoder.h"
#include "srsgnb/phy/upper/channel_processors/pdsch_modulator.h"
#include "srsgnb/phy/upper/channel_processors/pdsch_processor.h"
#include "srsgnb/phy/upper/channel_processors/prach_detector.h"
#include "srsgnb/phy/upper/channel_processors/prach_generator.h"
#include "srsgnb/phy/upper/channel_processors/pucch_demodulator.h"
#include "srsgnb/phy/upper/channel_processors/pucch_detector.h"
#include "srsgnb/phy/upper/channel_processors/pucch_processor.h"
#include "srsgnb/phy/upper/channel_processors/pusch_decoder.h"
#include "srsgnb/phy/upper/channel_processors/pusch_demodulator.h"
#include "srsgnb/phy/upper/channel_processors/pusch_processor.h"
#include "srsgnb/phy/upper/channel_processors/ssb_processor.h"
#include "srsgnb/phy/upper/channel_processors/uci_decoder.h"
#include "srsgnb/phy/upper/channel_processors/ulsch_demultiplex.h"
#include "srsgnb/phy/upper/equalization/equalization_factories.h"
#include "srsgnb/phy/upper/signal_processors/signal_processor_factories.h"
#include <memory>

namespace srsgnb {

class prach_generator_factory;

class pbch_encoder_factory
{
public:
  virtual ~pbch_encoder_factory()                = default;
  virtual std::unique_ptr<pbch_encoder> create() = 0;
};

std::shared_ptr<pbch_encoder_factory>
create_pbch_encoder_factory_sw(std::shared_ptr<crc_calculator_factory>          crc_factory,
                               std::shared_ptr<pseudo_random_generator_factory> prg_factory,
                               std::shared_ptr<polar_factory>                   polar_factory);

class pbch_modulator_factory
{
public:
  virtual ~pbch_modulator_factory()                = default;
  virtual std::unique_ptr<pbch_modulator> create() = 0;
};

std::shared_ptr<pbch_modulator_factory>
    create_pbch_modulator_factory_sw(std::shared_ptr<channel_modulation_factory>,
                                     std::shared_ptr<pseudo_random_generator_factory>);

class pdcch_modulator_factory
{
public:
  virtual ~pdcch_modulator_factory()                = default;
  virtual std::unique_ptr<pdcch_modulator> create() = 0;
};

std::shared_ptr<pdcch_modulator_factory>
    create_pdcch_modulator_factory_sw(std::shared_ptr<channel_modulation_factory>,
                                      std::shared_ptr<pseudo_random_generator_factory>);

class pdcch_encoder_factory
{
public:
  virtual ~pdcch_encoder_factory()                = default;
  virtual std::unique_ptr<pdcch_encoder> create() = 0;
};

std::shared_ptr<pdcch_encoder_factory>
create_pdcch_encoder_factory_sw(std::shared_ptr<crc_calculator_factory> crc_factory,
                                std::shared_ptr<polar_factory>          encoder_factory);

class pdcch_processor_factory
{
public:
  virtual ~pdcch_processor_factory()                = default;
  virtual std::unique_ptr<pdcch_processor> create() = 0;
};

std::shared_ptr<pdcch_processor_factory>
create_pdcch_processor_factory_sw(std::shared_ptr<pdcch_encoder_factory>        encoder_factory,
                                  std::shared_ptr<pdcch_modulator_factory>      modulator_factory,
                                  std::shared_ptr<dmrs_pdcch_processor_factory> dmrs_factory);

class pdsch_encoder_factory
{
public:
  virtual ~pdsch_encoder_factory()                = default;
  virtual std::unique_ptr<pdsch_encoder> create() = 0;
};

struct pdsch_encoder_factory_sw_configuration {
  std::shared_ptr<ldpc_encoder_factory>      encoder_factory;
  std::shared_ptr<ldpc_rate_matcher_factory> rate_matcher_factory;
  std::shared_ptr<ldpc_segmenter_tx_factory> segmenter_factory;
};

std::shared_ptr<pdsch_encoder_factory> create_pdsch_encoder_factory_sw(pdsch_encoder_factory_sw_configuration& config);

class pdsch_modulator_factory
{
public:
  virtual ~pdsch_modulator_factory()                = default;
  virtual std::unique_ptr<pdsch_modulator> create() = 0;
};

std::shared_ptr<pdsch_modulator_factory>
    create_pdsch_modulator_factory_sw(std::shared_ptr<channel_modulation_factory>,
                                      std::shared_ptr<pseudo_random_generator_factory>);

class pdsch_processor_factory
{
public:
  virtual ~pdsch_processor_factory()                = default;
  virtual std::unique_ptr<pdsch_processor> create() = 0;
};

std::shared_ptr<pdsch_processor_factory>
create_pdsch_processor_factory_sw(std::shared_ptr<pdsch_encoder_factory>        encoder_factory,
                                  std::shared_ptr<pdsch_modulator_factory>      modulator_factory,
                                  std::shared_ptr<dmrs_pdsch_processor_factory> dmrs_factory);

class prach_detector_factory
{
public:
  virtual ~prach_detector_factory()                = default;
  virtual std::unique_ptr<prach_detector> create() = 0;
};

std::shared_ptr<prach_detector_factory>
create_prach_detector_factory_simple(std::shared_ptr<dft_processor_factory>   dft_factory,
                                     std::shared_ptr<prach_generator_factory> prach_gen_factory,
                                     unsigned                                 dft_size_detector);

class prach_generator_factory
{
public:
  virtual ~prach_generator_factory()                = default;
  virtual std::unique_ptr<prach_generator> create() = 0;
};

std::shared_ptr<prach_generator_factory>
create_prach_generator_factory_sw(std::shared_ptr<dft_processor_factory> dft_factory);

class pucch_detector_factory
{
public:
  virtual ~pucch_detector_factory()                = default;
  virtual std::unique_ptr<pucch_detector> create() = 0;
};

std::shared_ptr<pucch_detector_factory>
create_pucch_detector_factory_sw(std::shared_ptr<low_papr_sequence_collection_factory> lpcf,
                                 std::shared_ptr<pseudo_random_generator_factory>      prgf);

class pucch_processor_factory
{
public:
  virtual ~pucch_processor_factory()                = default;
  virtual std::unique_ptr<pucch_processor> create() = 0;
};

std::shared_ptr<pucch_processor_factory>
create_pucch_processor_factory_sw(std::shared_ptr<dmrs_pucch_estimator_factory>        dmrs_factory,
                                  std::shared_ptr<pucch_detector_factory>              detector_factory,
                                  const channel_estimate::channel_estimate_dimensions& channel_estimate_dimensions);

class pusch_decoder_factory
{
public:
  virtual ~pusch_decoder_factory()                = default;
  virtual std::unique_ptr<pusch_decoder> create() = 0;
};

struct pusch_decoder_factory_sw_configuration {
  std::shared_ptr<crc_calculator_factory>      crc_factory;
  std::shared_ptr<ldpc_decoder_factory>        decoder_factory;
  std::shared_ptr<ldpc_rate_dematcher_factory> dematcher_factory;
  std::shared_ptr<ldpc_segmenter_rx_factory>   segmenter_factory;
};

std::shared_ptr<pusch_decoder_factory> create_pusch_decoder_factory_sw(pusch_decoder_factory_sw_configuration& config);

class pusch_demodulator_factory
{
public:
  virtual ~pusch_demodulator_factory()                = default;
  virtual std::unique_ptr<pusch_demodulator> create() = 0;
};

std::shared_ptr<pusch_demodulator_factory>
create_pusch_demodulator_factory_sw(std::shared_ptr<channel_equalizer_factory>       equalizer_factory,
                                    std::shared_ptr<channel_modulation_factory>      demodulation_factory,
                                    std::shared_ptr<pseudo_random_generator_factory> prg_factory);

class pusch_processor_factory
{
public:
  virtual ~pusch_processor_factory()                = default;
  virtual std::unique_ptr<pusch_processor> create() = 0;
};

struct pusch_processor_factory_sw_configuration {
  std::shared_ptr<dmrs_pusch_estimator_factory> estimator_factory;
  std::shared_ptr<pusch_demodulator_factory>    demodulator_factory;
  std::shared_ptr<pusch_decoder_factory>        decoder_factory;
  channel_estimate::channel_estimate_dimensions ch_estimate_dimensions;
};

std::shared_ptr<pusch_processor_factory>
create_pusch_processor_factory_sw(pusch_processor_factory_sw_configuration& config);

class ssb_processor_factory
{
public:
  virtual ~ssb_processor_factory()                = default;
  virtual std::unique_ptr<ssb_processor> create() = 0;
};

struct ssb_processor_factory_sw_configuration {
  std::shared_ptr<pbch_encoder_factory>        encoder_factory;
  std::shared_ptr<pbch_modulator_factory>      modulator_factory;
  std::shared_ptr<dmrs_pbch_processor_factory> dmrs_factory;
  std::shared_ptr<pss_processor_factory>       pss_factory;
  std::shared_ptr<sss_processor_factory>       sss_factory;
};

std::shared_ptr<ssb_processor_factory> create_ssb_processor_factory_sw(ssb_processor_factory_sw_configuration& config);

class uci_decoder_factory
{
public:
  virtual ~uci_decoder_factory()                = default;
  virtual std::unique_ptr<uci_decoder> create() = 0;
};

struct uci_decoder_factory_sw_configuration {
  std::shared_ptr<short_block_detector_factory> decoder_factory;
};

std::shared_ptr<uci_decoder_factory> create_uci_decoder_factory_sw(uci_decoder_factory_sw_configuration& config);

class ulsch_demultiplex_factory
{
public:
  virtual ~ulsch_demultiplex_factory()                = default;
  virtual std::unique_ptr<ulsch_demultiplex> create() = 0;
};

std::shared_ptr<ulsch_demultiplex_factory> create_ulsch_demultiplex_factory_sw();

class pucch_demodulator_factory
{
public:
  virtual ~pucch_demodulator_factory()                = default;
  virtual std::unique_ptr<pucch_demodulator> create() = 0;
};

std::shared_ptr<pucch_demodulator_factory>
create_pucch_demodulator_factory_sw(std::shared_ptr<channel_equalizer_factory>       equalizer_factory,
                                    std::shared_ptr<channel_modulation_factory>      demodulation_factory,
                                    std::shared_ptr<pseudo_random_generator_factory> prg_factory);

} // namespace srsgnb
