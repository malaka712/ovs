/*
 * Copyright 2013-present Barefoot Networks, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * File:   ovs_match_odp_util.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_ODP_UTIL_H
#define	OVS_MATCH_ODP_UTIL_H 1

/* -- Called in lib/odp-util.c -- */
#define OVS_KEY_ATTRS_TO_STRING_CASES \
    case OVS_KEY_ATTR__ETHERNET_: return "ethernet_"; \
    case OVS_KEY_ATTR__INTRINSIC_METADATA: return "intrinsic_metadata"; \
    case OVS_KEY_ATTR_VALID: return "valid"; \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_FORMAT_ODP_KEY_ATTR_CASES \
    case OVS_KEY_ATTR__ETHERNET_: { \
        const struct ovs_key__ethernet_ *key = nl_attr_get(a); \
        const struct ovs_key__ethernet_ *mask = ma ? nl_attr_get(ma) : NULL; \
        \
        format_bex(ds, "ethernet__dstAddr", (const uint8_t *) &key->ethernet__dstAddr, \
                   mask ? (const uint8_t (*)[]) &mask->ethernet__dstAddr : NULL, \
                   sizeof(struct ethernet__dstAddr_t), verbose); \
        format_bex(ds, "ethernet__srcAddr", (const uint8_t *) &key->ethernet__srcAddr, \
                   mask ? (const uint8_t (*)[]) &mask->ethernet__srcAddr : NULL, \
                   sizeof(struct ethernet__srcAddr_t), verbose); \
        format_be16x(ds, "ethernet__etherType", key->ethernet__etherType, MASK(mask, ethernet__etherType), verbose); \
        ds_chomp(ds, ','); \
        break; \
    } \
    case OVS_KEY_ATTR__INTRINSIC_METADATA: { \
        const struct ovs_key__intrinsic_metadata *key = nl_attr_get(a); \
        const struct ovs_key__intrinsic_metadata *mask = ma ? nl_attr_get(ma) : NULL; \
        \
        format_u8x(ds, "intrinsic_metadata_mcast_grp_egress_rid", key->intrinsic_metadata_mcast_grp_egress_rid, MASK(mask, intrinsic_metadata_mcast_grp_egress_rid), verbose); \
        format_be16x(ds, "intrinsic_metadata_mcast_hash", key->intrinsic_metadata_mcast_hash, MASK(mask, intrinsic_metadata_mcast_hash), verbose); \
        format_be32x(ds, "intrinsic_metadata_lf_field_list", key->intrinsic_metadata_lf_field_list, MASK(mask, intrinsic_metadata_lf_field_list), verbose); \
        ds_chomp(ds, ','); \
        break; \
    } \
    case OVS_KEY_ATTR_VALID: { \
        const struct ovs_key_valid *key = nl_attr_get(a); \
        const struct ovs_key_valid *mask = ma ? nl_attr_get(ma) : NULL; \
        \
        format_u8x(ds, "ethernet__valid", key->_ethernet__valid, MASK(mask, _ethernet__valid), verbose); \
        ds_chomp(ds, ','); \
        break; \
    } \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_SET_FUNC_DECLS \
    static void \
    get__ethernet__key(const struct flow *flow, struct ovs_key__ethernet_ *_ethernet_); \
    static void \
    put__ethernet__key(const struct ovs_key__ethernet_ *_ethernet_, struct flow *flow); \
    \
    static void \
    get__intrinsic_metadata_key(const struct flow *flow, struct ovs_key__intrinsic_metadata *_intrinsic_metadata); \
    static void \
    put__intrinsic_metadata_key(const struct ovs_key__intrinsic_metadata *_intrinsic_metadata, struct flow *flow); \
    \
    static void \
    get_valid_key(const struct flow *flow, struct ovs_key_valid *valid); \
    static void \
    put_valid_key(const struct ovs_key_valid *valid, struct flow *flow); \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_SET_FUNC_DEFS \
    static void \
    get__ethernet__key(const struct flow *flow, struct ovs_key__ethernet_ *_ethernet_) \
    { \
        _ethernet_->ethernet__dstAddr = flow->_ethernet_.hdr.ethernet__dstAddr; \
        _ethernet_->ethernet__srcAddr = flow->_ethernet_.hdr.ethernet__srcAddr; \
        _ethernet_->ethernet__etherType = flow->_ethernet_.hdr.ethernet__etherType; \
    } \
    \
    static void \
    put__ethernet__key(const struct ovs_key__ethernet_ *_ethernet_, struct flow *flow) \
    { \
        flow->_ethernet_.hdr.ethernet__dstAddr = _ethernet_->ethernet__dstAddr; \
        flow->_ethernet_.hdr.ethernet__srcAddr = _ethernet_->ethernet__srcAddr; \
        flow->_ethernet_.hdr.ethernet__etherType = _ethernet_->ethernet__etherType; \
    } \
    \
    static void \
    get__intrinsic_metadata_key(const struct flow *flow, struct ovs_key__intrinsic_metadata *_intrinsic_metadata) \
    { \
        _intrinsic_metadata->intrinsic_metadata_mcast_grp_egress_rid = flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid; \
        _intrinsic_metadata->intrinsic_metadata_mcast_hash = flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash; \
        _intrinsic_metadata->intrinsic_metadata_lf_field_list = flow->_intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list; \
    } \
    \
    static void \
    put__intrinsic_metadata_key(const struct ovs_key__intrinsic_metadata *_intrinsic_metadata, struct flow *flow) \
    { \
        flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid = _intrinsic_metadata->intrinsic_metadata_mcast_grp_egress_rid; \
        flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash = _intrinsic_metadata->intrinsic_metadata_mcast_hash; \
        flow->_intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list = _intrinsic_metadata->intrinsic_metadata_lf_field_list; \
    } \
    \
    static void \
    get_valid_key(const struct flow *flow, struct ovs_key_valid *valid) \
    { \
        valid->_ethernet__valid = flow->valid.hdr._ethernet__valid; \
    } \
    \
    static void \
    put_valid_key(const struct ovs_key_valid *valid, struct flow *flow) \
    { \
        flow->valid.hdr._ethernet__valid = valid->_ethernet__valid; \
    } \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_COMMIT_ACTION_FUNCS \
    static void \
    commit_set__ethernet__action(const struct flow *flow, struct flow *base_flow, \
               struct ofpbuf *odp_actions, \
               struct flow_wildcards *wc, \
               bool use_masked) \
    { \
        struct ovs_key__ethernet_ key, base, mask; \
        \
        get__ethernet__key(flow, &key); \
        get__ethernet__key(base_flow, &base); \
        get__ethernet__key(&wc->masks, &mask); \
        \
        if (commit(OVS_KEY_ATTR__ETHERNET_, use_masked, \
                   &key, &base, &mask, sizeof key, odp_actions)) { \
            put__ethernet__key(&base, base_flow); \
            put__ethernet__key(&mask, &wc->masks); \
        } \
    } \
    \
    static void \
    commit_set_valid_action(const struct flow *flow, struct flow *base_flow, \
               struct ofpbuf *odp_actions, \
               struct flow_wildcards *wc, \
               bool use_masked) \
    { \
        struct ovs_key_valid key, base, mask; \
        \
        get_valid_key(flow, &key); \
        get_valid_key(base_flow, &base); \
        get_valid_key(&wc->masks, &mask); \
        \
        if (commit(OVS_KEY_ATTR_VALID, use_masked, \
                   &key, &base, &mask, sizeof key, odp_actions)) { \
            put_valid_key(&base, base_flow); \
            put_valid_key(&mask, &wc->masks); \
        } \
    } \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_COMMIT_ODP_ACTIONS_FUNCS \
    commit_set__ethernet__action(flow, base, odp_actions, wc, use_masked); \
    commit_set_valid_action(flow, base, odp_actions, wc, use_masked); \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_FLOW_KEY_ATTR_LENS \
    [OVS_KEY_ATTR__ETHERNET_] = { .len = sizeof(struct ovs_key__ethernet_) }, \
    [OVS_KEY_ATTR__INTRINSIC_METADATA] = { .len = sizeof(struct ovs_key__intrinsic_metadata) }, \
    [OVS_KEY_ATTR_VALID] = { .len = sizeof(struct ovs_key_valid) }, \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_FLOW_KEY_FROM_FLOW \
    struct ovs_key__ethernet_ *_ethernet_; \
    _ethernet_ = nl_msg_put_unspec_uninit(buf, OVS_KEY_ATTR__ETHERNET_, sizeof *_ethernet_); \
    get__ethernet__key(data, _ethernet_); \
    \
    struct ovs_key__intrinsic_metadata *_intrinsic_metadata; \
    _intrinsic_metadata = nl_msg_put_unspec_uninit(buf, OVS_KEY_ATTR__INTRINSIC_METADATA, sizeof *_intrinsic_metadata); \
    get__intrinsic_metadata_key(data, _intrinsic_metadata); \
    \
    struct ovs_key_valid *valid; \
    valid = nl_msg_put_unspec_uninit(buf, OVS_KEY_ATTR_VALID, sizeof *valid); \
    get_valid_key(data, valid); \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_FLOW_KEY_TO_FLOW \
    if (present_attrs & (UINT64_C(1) << OVS_KEY_ATTR__ETHERNET_)) { \
        const struct ovs_key__ethernet_ *_ethernet_; \
        \
        _ethernet_ = nl_attr_get(attrs[OVS_KEY_ATTR__ETHERNET_]); \
        put__ethernet__key(_ethernet_, flow); \
        if (is_mask) { \
            expected_attrs |= UINT64_C(1) << OVS_KEY_ATTR__ETHERNET_; \
        } \
    } \
    if (!is_mask) { \
        expected_attrs |= UINT64_C(1) << OVS_KEY_ATTR__ETHERNET_; \
    } \
    \
    if (present_attrs & (UINT64_C(1) << OVS_KEY_ATTR__INTRINSIC_METADATA)) { \
        const struct ovs_key__intrinsic_metadata *_intrinsic_metadata; \
        \
        _intrinsic_metadata = nl_attr_get(attrs[OVS_KEY_ATTR__INTRINSIC_METADATA]); \
        put__intrinsic_metadata_key(_intrinsic_metadata, flow); \
        if (is_mask) { \
            expected_attrs |= UINT64_C(1) << OVS_KEY_ATTR__INTRINSIC_METADATA; \
        } \
    } \
    if (!is_mask) { \
        expected_attrs |= UINT64_C(1) << OVS_KEY_ATTR__INTRINSIC_METADATA; \
    } \
    \
    if (present_attrs & (UINT64_C(1) << OVS_KEY_ATTR_VALID)) { \
        const struct ovs_key_valid *valid; \
        \
        valid = nl_attr_get(attrs[OVS_KEY_ATTR_VALID]); \
        put_valid_key(valid, flow); \
        if (is_mask) { \
            expected_attrs |= UINT64_C(1) << OVS_KEY_ATTR_VALID; \
        } \
    } \
    if (!is_mask) { \
        expected_attrs |= UINT64_C(1) << OVS_KEY_ATTR_VALID; \
    } \
    \

#endif	/* OVS_MATCH_ODP_UTIL_H */