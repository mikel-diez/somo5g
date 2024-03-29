/*
 *
 * Copyright 2021-2024 Software Radio Systems Limited
 *
 * This file is part of srsRAN.
 *
 * srsRAN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsRAN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

/*******************************************************************************
 *
 *                     3GPP TS ASN1 E2SM v15.3.0 (2019-03)
 *
 ******************************************************************************/

#pragma once

#include "../asn1_utils.h"
#include <cstdio>
#include <stdarg.h>

namespace asn1 {
namespace e2sm {

/*******************************************************************************
 *                             Constant Definitions
 ******************************************************************************/

#define ASN1_E2SM_MAX_E1_APID 65535
#define ASN1_E2SM_MAX_F1_APID 4
#define ASN1_E2SM_MAX_EARFCN 65535
#define ASN1_E2SM_MAX_NRARFCN 3279165
#define ASN1_E2SM_MAXNOOF_NR_CELL_BANDS 32

/*******************************************************************************
 *                              Struct Definitions
 ******************************************************************************/

// EUTRA-CGI ::= SEQUENCE
struct eutra_cgi_s {
  bool                             ext = false;
  fixed_octstring<3, true>         plmn_id;
  fixed_bitstring<28, false, true> eutra_cell_id;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// NR-CGI ::= SEQUENCE
struct nr_cgi_s {
  bool                             ext = false;
  fixed_octstring<3, true>         plmn_id;
  fixed_bitstring<36, false, true> nrcell_id;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// CGI ::= CHOICE
struct cgi_c {
  struct types_opts {
    enum options { nr_cgi, eutra_cgi, /*...*/ nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  cgi_c() = default;
  cgi_c(const cgi_c& other);
  cgi_c& operator=(const cgi_c& other);
  ~cgi_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  nr_cgi_s& nr_cgi()
  {
    assert_choice_type(types::nr_cgi, type_, "CGI");
    return c.get<nr_cgi_s>();
  }
  eutra_cgi_s& eutra_cgi()
  {
    assert_choice_type(types::eutra_cgi, type_, "CGI");
    return c.get<eutra_cgi_s>();
  }
  const nr_cgi_s& nr_cgi() const
  {
    assert_choice_type(types::nr_cgi, type_, "CGI");
    return c.get<nr_cgi_s>();
  }
  const eutra_cgi_s& eutra_cgi() const
  {
    assert_choice_type(types::eutra_cgi, type_, "CGI");
    return c.get<eutra_cgi_s>();
  }
  nr_cgi_s&    set_nr_cgi();
  eutra_cgi_s& set_eutra_cgi();

private:
  types                                  type_;
  choice_buffer_t<eutra_cgi_s, nr_cgi_s> c;

  void destroy_();
};

// GUAMI ::= SEQUENCE
struct guami_s {
  bool                             ext = false;
  fixed_octstring<3, true>         plmn_id;
  fixed_bitstring<8, false, true>  amf_region_id;
  fixed_bitstring<10, false, true> amf_set_id;
  fixed_bitstring<6, false, true>  amf_pointer;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// GUMMEI ::= SEQUENCE
struct gummei_s {
  bool                     ext = false;
  fixed_octstring<3, true> plmn_id;
  fixed_octstring<2, true> mme_group_id;
  fixed_octstring<1, true> mme_code;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// CoreCPID ::= CHOICE
struct core_cpid_c {
  struct types_opts {
    enum options { five_gc, epc, /*...*/ nulltype } value;
    typedef uint8_t number_type;

    const char* to_string() const;
    uint8_t     to_number() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  core_cpid_c() = default;
  core_cpid_c(const core_cpid_c& other);
  core_cpid_c& operator=(const core_cpid_c& other);
  ~core_cpid_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  guami_s& five_gc()
  {
    assert_choice_type(types::five_gc, type_, "CoreCPID");
    return c.get<guami_s>();
  }
  gummei_s& epc()
  {
    assert_choice_type(types::epc, type_, "CoreCPID");
    return c.get<gummei_s>();
  }
  const guami_s& five_gc() const
  {
    assert_choice_type(types::five_gc, type_, "CoreCPID");
    return c.get<guami_s>();
  }
  const gummei_s& epc() const
  {
    assert_choice_type(types::epc, type_, "CoreCPID");
    return c.get<gummei_s>();
  }
  guami_s&  set_five_gc();
  gummei_s& set_epc();

private:
  types                              type_;
  choice_buffer_t<guami_s, gummei_s> c;

  void destroy_();
};

// ENB-ID ::= CHOICE
struct enb_id_c {
  struct types_opts {
    enum options { macro_enb_id, home_enb_id, /*...*/ short_macro_enb_id, long_macro_enb_id, nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true, 2> types;

  // choice methods
  enb_id_c() = default;
  enb_id_c(const enb_id_c& other);
  enb_id_c& operator=(const enb_id_c& other);
  ~enb_id_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  fixed_bitstring<20, false, true>& macro_enb_id()
  {
    assert_choice_type(types::macro_enb_id, type_, "ENB-ID");
    return c.get<fixed_bitstring<20, false, true>>();
  }
  fixed_bitstring<28, false, true>& home_enb_id()
  {
    assert_choice_type(types::home_enb_id, type_, "ENB-ID");
    return c.get<fixed_bitstring<28, false, true>>();
  }
  fixed_bitstring<18, false, true>& short_macro_enb_id()
  {
    assert_choice_type(types::short_macro_enb_id, type_, "ENB-ID");
    return c.get<fixed_bitstring<18, false, true>>();
  }
  fixed_bitstring<21, false, true>& long_macro_enb_id()
  {
    assert_choice_type(types::long_macro_enb_id, type_, "ENB-ID");
    return c.get<fixed_bitstring<21, false, true>>();
  }
  const fixed_bitstring<20, false, true>& macro_enb_id() const
  {
    assert_choice_type(types::macro_enb_id, type_, "ENB-ID");
    return c.get<fixed_bitstring<20, false, true>>();
  }
  const fixed_bitstring<28, false, true>& home_enb_id() const
  {
    assert_choice_type(types::home_enb_id, type_, "ENB-ID");
    return c.get<fixed_bitstring<28, false, true>>();
  }
  const fixed_bitstring<18, false, true>& short_macro_enb_id() const
  {
    assert_choice_type(types::short_macro_enb_id, type_, "ENB-ID");
    return c.get<fixed_bitstring<18, false, true>>();
  }
  const fixed_bitstring<21, false, true>& long_macro_enb_id() const
  {
    assert_choice_type(types::long_macro_enb_id, type_, "ENB-ID");
    return c.get<fixed_bitstring<21, false, true>>();
  }
  fixed_bitstring<20, false, true>& set_macro_enb_id();
  fixed_bitstring<28, false, true>& set_home_enb_id();
  fixed_bitstring<18, false, true>& set_short_macro_enb_id();
  fixed_bitstring<21, false, true>& set_long_macro_enb_id();

private:
  types                                             type_;
  choice_buffer_t<fixed_bitstring<28, false, true>> c;

  void destroy_();
};

// GlobalENB-ID ::= SEQUENCE
struct global_enb_id_s {
  bool                     ext = false;
  fixed_octstring<3, true> plmn_id;
  enb_id_c                 enb_id;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// GNB-ID ::= CHOICE
struct gnb_id_c {
  struct types_opts {
    enum options { gnb_id, /*...*/ nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  types       type() const { return types::gnb_id; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  bounded_bitstring<22, 32, false, true>&       gnb_id() { return c; }
  const bounded_bitstring<22, 32, false, true>& gnb_id() const { return c; }

private:
  bounded_bitstring<22, 32, false, true> c;
};

// GlobalGNB-ID ::= SEQUENCE
struct global_gnb_id_s {
  bool                     ext = false;
  fixed_octstring<3, true> plmn_id;
  gnb_id_c                 gnb_id;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// NgENB-ID ::= CHOICE
struct ng_enb_id_c {
  struct types_opts {
    enum options { macro_ng_enb_id, short_macro_ng_enb_id, long_macro_ng_enb_id, /*...*/ nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  ng_enb_id_c() = default;
  ng_enb_id_c(const ng_enb_id_c& other);
  ng_enb_id_c& operator=(const ng_enb_id_c& other);
  ~ng_enb_id_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  fixed_bitstring<20, false, true>& macro_ng_enb_id()
  {
    assert_choice_type(types::macro_ng_enb_id, type_, "NgENB-ID");
    return c.get<fixed_bitstring<20, false, true>>();
  }
  fixed_bitstring<18, false, true>& short_macro_ng_enb_id()
  {
    assert_choice_type(types::short_macro_ng_enb_id, type_, "NgENB-ID");
    return c.get<fixed_bitstring<18, false, true>>();
  }
  fixed_bitstring<21, false, true>& long_macro_ng_enb_id()
  {
    assert_choice_type(types::long_macro_ng_enb_id, type_, "NgENB-ID");
    return c.get<fixed_bitstring<21, false, true>>();
  }
  const fixed_bitstring<20, false, true>& macro_ng_enb_id() const
  {
    assert_choice_type(types::macro_ng_enb_id, type_, "NgENB-ID");
    return c.get<fixed_bitstring<20, false, true>>();
  }
  const fixed_bitstring<18, false, true>& short_macro_ng_enb_id() const
  {
    assert_choice_type(types::short_macro_ng_enb_id, type_, "NgENB-ID");
    return c.get<fixed_bitstring<18, false, true>>();
  }
  const fixed_bitstring<21, false, true>& long_macro_ng_enb_id() const
  {
    assert_choice_type(types::long_macro_ng_enb_id, type_, "NgENB-ID");
    return c.get<fixed_bitstring<21, false, true>>();
  }
  fixed_bitstring<20, false, true>& set_macro_ng_enb_id();
  fixed_bitstring<18, false, true>& set_short_macro_ng_enb_id();
  fixed_bitstring<21, false, true>& set_long_macro_ng_enb_id();

private:
  types                                             type_;
  choice_buffer_t<fixed_bitstring<21, false, true>> c;

  void destroy_();
};

// GlobalNgENB-ID ::= SEQUENCE
struct global_ng_enb_id_s {
  bool                     ext = false;
  fixed_octstring<3, true> plmn_id;
  ng_enb_id_c              ng_enb_id;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// GlobalNGRANNodeID ::= CHOICE
struct global_ngran_node_id_c {
  struct types_opts {
    enum options { gnb, ng_enb, /*...*/ nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  global_ngran_node_id_c() = default;
  global_ngran_node_id_c(const global_ngran_node_id_c& other);
  global_ngran_node_id_c& operator=(const global_ngran_node_id_c& other);
  ~global_ngran_node_id_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  global_gnb_id_s& gnb()
  {
    assert_choice_type(types::gnb, type_, "GlobalNGRANNodeID");
    return c.get<global_gnb_id_s>();
  }
  global_ng_enb_id_s& ng_enb()
  {
    assert_choice_type(types::ng_enb, type_, "GlobalNGRANNodeID");
    return c.get<global_ng_enb_id_s>();
  }
  const global_gnb_id_s& gnb() const
  {
    assert_choice_type(types::gnb, type_, "GlobalNGRANNodeID");
    return c.get<global_gnb_id_s>();
  }
  const global_ng_enb_id_s& ng_enb() const
  {
    assert_choice_type(types::ng_enb, type_, "GlobalNGRANNodeID");
    return c.get<global_ng_enb_id_s>();
  }
  global_gnb_id_s&    set_gnb();
  global_ng_enb_id_s& set_ng_enb();

private:
  types                                                type_;
  choice_buffer_t<global_gnb_id_s, global_ng_enb_id_s> c;

  void destroy_();
};

// EN-GNB-ID ::= CHOICE
struct en_gnb_id_c {
  struct types_opts {
    enum options { en_g_nb_id, /*...*/ nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  types       type() const { return types::en_g_nb_id; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  bounded_bitstring<22, 32, false, true>&       en_g_nb_id() { return c; }
  const bounded_bitstring<22, 32, false, true>& en_g_nb_id() const { return c; }

private:
  bounded_bitstring<22, 32, false, true> c;
};

// GlobalenGNB-ID ::= SEQUENCE
struct globalen_gnb_id_s {
  bool                     ext = false;
  fixed_octstring<3, true> plmn_id;
  en_gnb_id_c              en_g_nb_id;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// GroupID ::= CHOICE
struct group_id_c {
  struct types_opts {
    enum options { five_gc, epc, /*...*/ nulltype } value;
    typedef uint8_t number_type;

    const char* to_string() const;
    uint8_t     to_number() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  group_id_c() = default;
  group_id_c(const group_id_c& other);
  group_id_c& operator=(const group_id_c& other);
  ~group_id_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  uint16_t& five_gc()
  {
    assert_choice_type(types::five_gc, type_, "GroupID");
    return c.get<uint16_t>();
  }
  uint16_t& epc()
  {
    assert_choice_type(types::epc, type_, "GroupID");
    return c.get<uint16_t>();
  }
  const uint16_t& five_gc() const
  {
    assert_choice_type(types::five_gc, type_, "GroupID");
    return c.get<uint16_t>();
  }
  const uint16_t& epc() const
  {
    assert_choice_type(types::epc, type_, "GroupID");
    return c.get<uint16_t>();
  }
  uint16_t& set_five_gc();
  uint16_t& set_epc();

private:
  types               type_;
  pod_choice_buffer_t c;

  void destroy_();
};

// InterfaceID-E1 ::= SEQUENCE
struct interface_id_e1_s {
  bool            ext = false;
  global_gnb_id_s global_gnb_id;
  uint64_t        gnb_cu_up_id = 0;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// InterfaceID-F1 ::= SEQUENCE
struct interface_id_f1_s {
  bool            ext = false;
  global_gnb_id_s global_gnb_id;
  uint64_t        gnb_du_id = 0;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// InterfaceID-NG ::= SEQUENCE
struct interface_id_ng_s {
  bool    ext = false;
  guami_s guami;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// InterfaceID-S1 ::= SEQUENCE
struct interface_id_s1_s {
  bool     ext = false;
  gummei_s gummei;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// InterfaceID-W1 ::= SEQUENCE
struct interface_id_w1_s {
  bool               ext = false;
  global_ng_enb_id_s global_ng_enb_id;
  uint64_t           ng_enb_du_id = 0;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// InterfaceID-X2 ::= SEQUENCE
struct interface_id_x2_s {
  struct node_type_c_ {
    struct types_opts {
      enum options { global_enb_id, global_en_g_nb_id, /*...*/ nulltype } value;

      const char* to_string() const;
    };
    typedef enumerated<types_opts, true> types;

    // choice methods
    node_type_c_() = default;
    node_type_c_(const node_type_c_& other);
    node_type_c_& operator=(const node_type_c_& other);
    ~node_type_c_() { destroy_(); }
    void        set(types::options e = types::nulltype);
    types       type() const { return type_; }
    SRSASN_CODE pack(bit_ref& bref) const;
    SRSASN_CODE unpack(cbit_ref& bref);
    void        to_json(json_writer& j) const;
    // getters
    global_enb_id_s& global_enb_id()
    {
      assert_choice_type(types::global_enb_id, type_, "nodeType");
      return c.get<global_enb_id_s>();
    }
    globalen_gnb_id_s& global_en_g_nb_id()
    {
      assert_choice_type(types::global_en_g_nb_id, type_, "nodeType");
      return c.get<globalen_gnb_id_s>();
    }
    const global_enb_id_s& global_enb_id() const
    {
      assert_choice_type(types::global_enb_id, type_, "nodeType");
      return c.get<global_enb_id_s>();
    }
    const globalen_gnb_id_s& global_en_g_nb_id() const
    {
      assert_choice_type(types::global_en_g_nb_id, type_, "nodeType");
      return c.get<globalen_gnb_id_s>();
    }
    global_enb_id_s&   set_global_enb_id();
    globalen_gnb_id_s& set_global_en_g_nb_id();

  private:
    types                                               type_;
    choice_buffer_t<global_enb_id_s, globalen_gnb_id_s> c;

    void destroy_();
  };

  // member variables
  bool         ext = false;
  node_type_c_ node_type;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// InterfaceID-Xn ::= SEQUENCE
struct interface_id_xn_s {
  bool                   ext = false;
  global_ngran_node_id_c global_ng_ran_id;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// InterfaceIdentifier ::= CHOICE
struct interface_id_c {
  struct types_opts {
    enum options { ng, xn, f1, e1, s1, x2, w1, /*...*/ nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  interface_id_c() = default;
  interface_id_c(const interface_id_c& other);
  interface_id_c& operator=(const interface_id_c& other);
  ~interface_id_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  interface_id_ng_s& ng()
  {
    assert_choice_type(types::ng, type_, "InterfaceIdentifier");
    return c.get<interface_id_ng_s>();
  }
  interface_id_xn_s& xn()
  {
    assert_choice_type(types::xn, type_, "InterfaceIdentifier");
    return c.get<interface_id_xn_s>();
  }
  interface_id_f1_s& f1()
  {
    assert_choice_type(types::f1, type_, "InterfaceIdentifier");
    return c.get<interface_id_f1_s>();
  }
  interface_id_e1_s& e1()
  {
    assert_choice_type(types::e1, type_, "InterfaceIdentifier");
    return c.get<interface_id_e1_s>();
  }
  interface_id_s1_s& s1()
  {
    assert_choice_type(types::s1, type_, "InterfaceIdentifier");
    return c.get<interface_id_s1_s>();
  }
  interface_id_x2_s& x2()
  {
    assert_choice_type(types::x2, type_, "InterfaceIdentifier");
    return c.get<interface_id_x2_s>();
  }
  interface_id_w1_s& w1()
  {
    assert_choice_type(types::w1, type_, "InterfaceIdentifier");
    return c.get<interface_id_w1_s>();
  }
  const interface_id_ng_s& ng() const
  {
    assert_choice_type(types::ng, type_, "InterfaceIdentifier");
    return c.get<interface_id_ng_s>();
  }
  const interface_id_xn_s& xn() const
  {
    assert_choice_type(types::xn, type_, "InterfaceIdentifier");
    return c.get<interface_id_xn_s>();
  }
  const interface_id_f1_s& f1() const
  {
    assert_choice_type(types::f1, type_, "InterfaceIdentifier");
    return c.get<interface_id_f1_s>();
  }
  const interface_id_e1_s& e1() const
  {
    assert_choice_type(types::e1, type_, "InterfaceIdentifier");
    return c.get<interface_id_e1_s>();
  }
  const interface_id_s1_s& s1() const
  {
    assert_choice_type(types::s1, type_, "InterfaceIdentifier");
    return c.get<interface_id_s1_s>();
  }
  const interface_id_x2_s& x2() const
  {
    assert_choice_type(types::x2, type_, "InterfaceIdentifier");
    return c.get<interface_id_x2_s>();
  }
  const interface_id_w1_s& w1() const
  {
    assert_choice_type(types::w1, type_, "InterfaceIdentifier");
    return c.get<interface_id_w1_s>();
  }
  interface_id_ng_s& set_ng();
  interface_id_xn_s& set_xn();
  interface_id_f1_s& set_f1();
  interface_id_e1_s& set_e1();
  interface_id_s1_s& set_s1();
  interface_id_x2_s& set_x2();
  interface_id_w1_s& set_w1();

private:
  types type_;
  choice_buffer_t<interface_id_e1_s,
                  interface_id_f1_s,
                  interface_id_ng_s,
                  interface_id_s1_s,
                  interface_id_w1_s,
                  interface_id_x2_s,
                  interface_id_xn_s>
      c;

  void destroy_();
};

// NR-ARFCN ::= SEQUENCE
struct nr_arfcn_s {
  bool     ext     = false;
  uint32_t nrarfcn = 0;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// SupportedSULFreqBandItem ::= SEQUENCE
struct supported_sul_freq_band_item_s {
  bool     ext              = false;
  uint16_t freq_band_ind_nr = 1;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// SupportedSULBandList ::= SEQUENCE (SIZE (0..32)) OF SupportedSULFreqBandItem
using supported_sul_band_list_l = dyn_array<supported_sul_freq_band_item_s>;

// NRFrequencyBandItem ::= SEQUENCE
struct nr_freq_band_item_s {
  bool                      ext              = false;
  uint16_t                  freq_band_ind_nr = 1;
  supported_sul_band_list_l supported_sul_band_list;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// NRFrequencyBand-List ::= SEQUENCE (SIZE (1..32)) OF NRFrequencyBandItem
using nr_freq_band_list_l = dyn_array<nr_freq_band_item_s>;

// NRFrequencyShift7p5khz ::= ENUMERATED
struct nr_freq_shift7p5khz_opts {
  enum options { false_value, true_value, /*...*/ nulltype } value;

  const char* to_string() const;
};
typedef enumerated<nr_freq_shift7p5khz_opts, true> nr_freq_shift7p5khz_e;

// NRFrequencyInfo ::= SEQUENCE
struct nr_freq_info_s {
  bool                  ext                      = false;
  bool                  freq_shift7p5khz_present = false;
  nr_arfcn_s            nr_arfcn;
  nr_freq_band_list_l   freq_band_list;
  nr_freq_shift7p5khz_e freq_shift7p5khz;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// QoSID ::= CHOICE
struct qo_sid_c {
  struct types_opts {
    enum options { five_gc, epc, /*...*/ nulltype } value;
    typedef uint8_t number_type;

    const char* to_string() const;
    uint8_t     to_number() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  qo_sid_c() = default;
  qo_sid_c(const qo_sid_c& other);
  qo_sid_c& operator=(const qo_sid_c& other);
  ~qo_sid_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  uint16_t& five_gc()
  {
    assert_choice_type(types::five_gc, type_, "QoSID");
    return c.get<uint16_t>();
  }
  uint16_t& epc()
  {
    assert_choice_type(types::epc, type_, "QoSID");
    return c.get<uint16_t>();
  }
  const uint16_t& five_gc() const
  {
    assert_choice_type(types::five_gc, type_, "QoSID");
    return c.get<uint16_t>();
  }
  const uint16_t& epc() const
  {
    assert_choice_type(types::epc, type_, "QoSID");
    return c.get<uint16_t>();
  }
  uint16_t& set_five_gc();
  uint16_t& set_epc();

private:
  types               type_;
  pod_choice_buffer_t c;

  void destroy_();
};

// RRCclass-LTE ::= ENUMERATED
struct rr_cclass_lte_opts {
  enum options {
    bcch_bch,
    bcch_bch_mbms,
    bcch_dl_sch,
    bcch_dl_sch_br,
    bcch_dl_sch_mbms,
    mcch,
    pcch,
    dl_ccch,
    dl_dcch,
    ul_ccch,
    ul_dcch,
    sc_mcch,
    // ...
    nulltype
  } value;

  const char* to_string() const;
};
typedef enumerated<rr_cclass_lte_opts, true> rr_cclass_lte_e;

// RRCclass-NR ::= ENUMERATED
struct rr_cclass_nr_opts {
  enum options { bcch_bch, bcch_dl_sch, dl_ccch, dl_dcch, pcch, ul_ccch, ul_ccch1, ul_dcch, /*...*/ nulltype } value;
  typedef uint8_t number_type;

  const char* to_string() const;
  uint8_t     to_number() const;
};
typedef enumerated<rr_cclass_nr_opts, true> rr_cclass_nr_e;

// RRC-MessageID ::= SEQUENCE
struct rrc_msg_id_s {
  struct rrc_type_c_ {
    struct types_opts {
      enum options { lte, nr, /*...*/ nulltype } value;

      const char* to_string() const;
    };
    typedef enumerated<types_opts, true> types;

    // choice methods
    rrc_type_c_() = default;
    rrc_type_c_(const rrc_type_c_& other);
    rrc_type_c_& operator=(const rrc_type_c_& other);
    ~rrc_type_c_() { destroy_(); }
    void        set(types::options e = types::nulltype);
    types       type() const { return type_; }
    SRSASN_CODE pack(bit_ref& bref) const;
    SRSASN_CODE unpack(cbit_ref& bref);
    void        to_json(json_writer& j) const;
    // getters
    rr_cclass_lte_e& lte()
    {
      assert_choice_type(types::lte, type_, "rrcType");
      return c.get<rr_cclass_lte_e>();
    }
    rr_cclass_nr_e& nr()
    {
      assert_choice_type(types::nr, type_, "rrcType");
      return c.get<rr_cclass_nr_e>();
    }
    const rr_cclass_lte_e& lte() const
    {
      assert_choice_type(types::lte, type_, "rrcType");
      return c.get<rr_cclass_lte_e>();
    }
    const rr_cclass_nr_e& nr() const
    {
      assert_choice_type(types::nr, type_, "rrcType");
      return c.get<rr_cclass_nr_e>();
    }
    rr_cclass_lte_e& set_lte();
    rr_cclass_nr_e&  set_nr();

  private:
    types               type_;
    pod_choice_buffer_t c;

    void destroy_();
  };

  // member variables
  bool        ext = false;
  rrc_type_c_ rrc_type;
  int64_t     msg_id = 0;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// S-NSSAI ::= SEQUENCE
struct s_nssai_s {
  bool                     ext        = false;
  bool                     sd_present = false;
  fixed_octstring<1, true> sst;
  fixed_octstring<3, true> sd;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// ServingCell-ARFCN ::= CHOICE
struct serving_cell_arfcn_c {
  struct types_opts {
    enum options { nr, eutra, /*...*/ nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  serving_cell_arfcn_c() = default;
  serving_cell_arfcn_c(const serving_cell_arfcn_c& other);
  serving_cell_arfcn_c& operator=(const serving_cell_arfcn_c& other);
  ~serving_cell_arfcn_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  nr_arfcn_s& nr()
  {
    assert_choice_type(types::nr, type_, "ServingCell-ARFCN");
    return c.get<nr_arfcn_s>();
  }
  uint32_t& eutra()
  {
    assert_choice_type(types::eutra, type_, "ServingCell-ARFCN");
    return c.get<uint32_t>();
  }
  const nr_arfcn_s& nr() const
  {
    assert_choice_type(types::nr, type_, "ServingCell-ARFCN");
    return c.get<nr_arfcn_s>();
  }
  const uint32_t& eutra() const
  {
    assert_choice_type(types::eutra, type_, "ServingCell-ARFCN");
    return c.get<uint32_t>();
  }
  nr_arfcn_s& set_nr();
  uint32_t&   set_eutra();

private:
  types                       type_;
  choice_buffer_t<nr_arfcn_s> c;

  void destroy_();
};

// ServingCell-PCI ::= CHOICE
struct serving_cell_pci_c {
  struct types_opts {
    enum options { nr, eutra, /*...*/ nulltype } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  serving_cell_pci_c() = default;
  serving_cell_pci_c(const serving_cell_pci_c& other);
  serving_cell_pci_c& operator=(const serving_cell_pci_c& other);
  ~serving_cell_pci_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  uint16_t& nr()
  {
    assert_choice_type(types::nr, type_, "ServingCell-PCI");
    return c.get<uint16_t>();
  }
  uint16_t& eutra()
  {
    assert_choice_type(types::eutra, type_, "ServingCell-PCI");
    return c.get<uint16_t>();
  }
  const uint16_t& nr() const
  {
    assert_choice_type(types::nr, type_, "ServingCell-PCI");
    return c.get<uint16_t>();
  }
  const uint16_t& eutra() const
  {
    assert_choice_type(types::eutra, type_, "ServingCell-PCI");
    return c.get<uint16_t>();
  }
  uint16_t& set_nr();
  uint16_t& set_eutra();

private:
  types               type_;
  pod_choice_buffer_t c;

  void destroy_();
};

// UEID-GNB-CU-CP-E1AP-ID-Item ::= SEQUENCE
struct ueid_gnb_cu_cp_e1_ap_id_item_s {
  bool     ext                   = false;
  uint64_t gnb_cu_cp_ue_e1_ap_id = 0;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID-GNB-CU-CP-F1AP-ID-Item ::= SEQUENCE
struct ueid_gnb_cu_cp_f1_ap_id_item_s {
  bool     ext                = false;
  uint64_t gnb_cu_ue_f1_ap_id = 0;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID-GNB-CU-CP-E1AP-ID-List ::= SEQUENCE (SIZE (1..65535)) OF UEID-GNB-CU-CP-E1AP-ID-Item
using ueid_gnb_cu_cp_e1_ap_id_list_l = dyn_array<ueid_gnb_cu_cp_e1_ap_id_item_s>;

// UEID-GNB-CU-F1AP-ID-List ::= SEQUENCE (SIZE (1..4)) OF UEID-GNB-CU-CP-F1AP-ID-Item
using ueid_gnb_cu_f1_ap_id_list_l = dyn_array<ueid_gnb_cu_cp_f1_ap_id_item_s>;

// UEID-EN-GNB ::= SEQUENCE
struct ueid_en_gnb_s {
  bool                           ext                          = false;
  bool                           m_enb_ue_x2ap_id_ext_present = false;
  bool                           gnb_cu_ue_f1_ap_id_present   = false;
  bool                           ran_ueid_present             = false;
  uint16_t                       m_enb_ue_x2ap_id             = 0;
  uint16_t                       m_enb_ue_x2ap_id_ext         = 0;
  global_enb_id_s                global_enb_id;
  uint64_t                       gnb_cu_ue_f1_ap_id = 0;
  ueid_gnb_cu_cp_e1_ap_id_list_l gnb_cu_cp_ue_e1_ap_id_list;
  fixed_octstring<8, true>       ran_ueid;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID-ENB ::= SEQUENCE
struct ueid_enb_s {
  bool            ext                          = false;
  bool            m_enb_ue_x2ap_id_present     = false;
  bool            m_enb_ue_x2ap_id_ext_present = false;
  bool            global_enb_id_present        = false;
  uint64_t        mme_ue_s1ap_id               = 0;
  gummei_s        gummei;
  uint16_t        m_enb_ue_x2ap_id     = 0;
  uint16_t        m_enb_ue_x2ap_id_ext = 0;
  global_enb_id_s global_enb_id;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID-GNB ::= SEQUENCE
struct ueid_gnb_s {
  bool                           ext                          = false;
  bool                           ran_ueid_present             = false;
  bool                           m_ng_ran_ue_xn_ap_id_present = false;
  bool                           global_gnb_id_present        = false;
  uint64_t                       amf_ue_ngap_id               = 0;
  guami_s                        guami;
  ueid_gnb_cu_f1_ap_id_list_l    gnb_cu_ue_f1_ap_id_list;
  ueid_gnb_cu_cp_e1_ap_id_list_l gnb_cu_cp_ue_e1_ap_id_list;
  fixed_octstring<8, true>       ran_ueid;
  uint64_t                       m_ng_ran_ue_xn_ap_id = 0;
  global_gnb_id_s                global_gnb_id;
  // ...
  copy_ptr<global_ngran_node_id_c> global_ng_ran_node_id;

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID-GNB-CU-UP ::= SEQUENCE
struct ueid_gnb_cu_up_s {
  bool                     ext                   = false;
  bool                     ran_ueid_present      = false;
  uint64_t                 gnb_cu_cp_ue_e1_ap_id = 0;
  fixed_octstring<8, true> ran_ueid;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID-GNB-DU ::= SEQUENCE
struct ueid_gnb_du_s {
  bool                     ext                = false;
  bool                     ran_ueid_present   = false;
  uint64_t                 gnb_cu_ue_f1_ap_id = 0;
  fixed_octstring<8, true> ran_ueid;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID-NG-ENB ::= SEQUENCE
struct ueid_ng_enb_s {
  bool               ext                           = false;
  bool               ng_enb_cu_ue_w1_ap_id_present = false;
  bool               m_ng_ran_ue_xn_ap_id_present  = false;
  bool               global_ng_enb_id_present      = false;
  uint64_t           amf_ue_ngap_id                = 0;
  guami_s            guami;
  uint64_t           ng_enb_cu_ue_w1_ap_id = 0;
  uint64_t           m_ng_ran_ue_xn_ap_id  = 0;
  global_ng_enb_id_s global_ng_enb_id;
  // ...
  copy_ptr<global_ngran_node_id_c> global_ng_ran_node_id;

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID-NG-ENB-DU ::= SEQUENCE
struct ueid_ng_enb_du_s {
  bool     ext                   = false;
  uint64_t ng_enb_cu_ue_w1_ap_id = 0;
  // ...

  // sequence methods
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
};

// UEID ::= CHOICE
struct ueid_c {
  struct types_opts {
    enum options {
      gnb_ueid,
      gnb_du_ueid,
      gnb_cu_up_ueid,
      ng_enb_ueid,
      ng_enb_du_ueid,
      en_g_nb_ueid,
      enb_ueid,
      // ...
      nulltype
    } value;

    const char* to_string() const;
  };
  typedef enumerated<types_opts, true> types;

  // choice methods
  ueid_c() = default;
  ueid_c(const ueid_c& other);
  ueid_c& operator=(const ueid_c& other);
  ~ueid_c() { destroy_(); }
  void        set(types::options e = types::nulltype);
  types       type() const { return type_; }
  SRSASN_CODE pack(bit_ref& bref) const;
  SRSASN_CODE unpack(cbit_ref& bref);
  void        to_json(json_writer& j) const;
  // getters
  ueid_gnb_s& gnb_ueid()
  {
    assert_choice_type(types::gnb_ueid, type_, "UEID");
    return c.get<ueid_gnb_s>();
  }
  ueid_gnb_du_s& gnb_du_ueid()
  {
    assert_choice_type(types::gnb_du_ueid, type_, "UEID");
    return c.get<ueid_gnb_du_s>();
  }
  ueid_gnb_cu_up_s& gnb_cu_up_ueid()
  {
    assert_choice_type(types::gnb_cu_up_ueid, type_, "UEID");
    return c.get<ueid_gnb_cu_up_s>();
  }
  ueid_ng_enb_s& ng_enb_ueid()
  {
    assert_choice_type(types::ng_enb_ueid, type_, "UEID");
    return c.get<ueid_ng_enb_s>();
  }
  ueid_ng_enb_du_s& ng_enb_du_ueid()
  {
    assert_choice_type(types::ng_enb_du_ueid, type_, "UEID");
    return c.get<ueid_ng_enb_du_s>();
  }
  ueid_en_gnb_s& en_g_nb_ueid()
  {
    assert_choice_type(types::en_g_nb_ueid, type_, "UEID");
    return c.get<ueid_en_gnb_s>();
  }
  ueid_enb_s& enb_ueid()
  {
    assert_choice_type(types::enb_ueid, type_, "UEID");
    return c.get<ueid_enb_s>();
  }
  const ueid_gnb_s& gnb_ueid() const
  {
    assert_choice_type(types::gnb_ueid, type_, "UEID");
    return c.get<ueid_gnb_s>();
  }
  const ueid_gnb_du_s& gnb_du_ueid() const
  {
    assert_choice_type(types::gnb_du_ueid, type_, "UEID");
    return c.get<ueid_gnb_du_s>();
  }
  const ueid_gnb_cu_up_s& gnb_cu_up_ueid() const
  {
    assert_choice_type(types::gnb_cu_up_ueid, type_, "UEID");
    return c.get<ueid_gnb_cu_up_s>();
  }
  const ueid_ng_enb_s& ng_enb_ueid() const
  {
    assert_choice_type(types::ng_enb_ueid, type_, "UEID");
    return c.get<ueid_ng_enb_s>();
  }
  const ueid_ng_enb_du_s& ng_enb_du_ueid() const
  {
    assert_choice_type(types::ng_enb_du_ueid, type_, "UEID");
    return c.get<ueid_ng_enb_du_s>();
  }
  const ueid_en_gnb_s& en_g_nb_ueid() const
  {
    assert_choice_type(types::en_g_nb_ueid, type_, "UEID");
    return c.get<ueid_en_gnb_s>();
  }
  const ueid_enb_s& enb_ueid() const
  {
    assert_choice_type(types::enb_ueid, type_, "UEID");
    return c.get<ueid_enb_s>();
  }
  ueid_gnb_s&       set_gnb_ueid();
  ueid_gnb_du_s&    set_gnb_du_ueid();
  ueid_gnb_cu_up_s& set_gnb_cu_up_ueid();
  ueid_ng_enb_s&    set_ng_enb_ueid();
  ueid_ng_enb_du_s& set_ng_enb_du_ueid();
  ueid_en_gnb_s&    set_en_g_nb_ueid();
  ueid_enb_s&       set_enb_ueid();

private:
  types type_;
  choice_buffer_t<ueid_en_gnb_s,
                  ueid_enb_s,
                  ueid_gnb_cu_up_s,
                  ueid_gnb_du_s,
                  ueid_gnb_s,
                  ueid_ng_enb_du_s,
                  ueid_ng_enb_s>
      c;

  void destroy_();
};

} // namespace e2sm
} // namespace asn1
