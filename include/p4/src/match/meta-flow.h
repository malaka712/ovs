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
 * File:   meta-flow.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_META_FLOW_H
#define	OVS_MATCH_META_FLOW_H 1

/* -- Called in lib/meta-flow.c -- */
#define OVS_GET_VALUE_CASES \
    case MFF_ETHERNET__DSTADDR: \
        memcpy(value->data, &flow->_ethernet_.hdr.ethernet__dstAddr, \
               sizeof flow->_ethernet_.hdr.ethernet__dstAddr); \
        break; \
    case MFF_ETHERNET__SRCADDR: \
        memcpy(value->data, &flow->_ethernet_.hdr.ethernet__srcAddr, \
               sizeof flow->_ethernet_.hdr.ethernet__srcAddr); \
        break; \
    case MFF_ETHERNET__ETHERTYPE: \
        value->be16 = flow->_ethernet_.hdr.ethernet__etherType; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID: \
        value->u8 = flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_HASH: \
        value->be16 = flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash; \
        break; \
    case MFF_INTRINSIC_METADATA_LF_FIELD_LIST: \
        value->be32 = flow->_intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list; \
        break; \
    case MFF_ETHERNET__VALID: \
        value->u8 = flow->valid.hdr._ethernet__valid; \
        break; \
    \

/* -- Called in lib/meta-flow.c -- */
#define OVS_IS_VALUE_VALID_CASES \
    case MFF_ETHERNET__DSTADDR: \
        return true; \
    case MFF_ETHERNET__SRCADDR: \
        return true; \
    case MFF_ETHERNET__ETHERTYPE: \
        return true; \
    case MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID: \
        return true; \
    case MFF_INTRINSIC_METADATA_MCAST_HASH: \
        return true; \
    case MFF_INTRINSIC_METADATA_LF_FIELD_LIST: \
        return true; \
    case MFF_ETHERNET__VALID: \
        return true; \
    \

/* -- Called in lib/meta-flow.c -- */
#define OVS_IS_ALL_WILD_CASES \
    case MFF_ETHERNET__DSTADDR: \
        return is_all_zeros(&wc->masks._ethernet_.hdr.ethernet__dstAddr, \
                            sizeof wc->masks._ethernet_.hdr.ethernet__dstAddr); \
    case MFF_ETHERNET__SRCADDR: \
        return is_all_zeros(&wc->masks._ethernet_.hdr.ethernet__srcAddr, \
                            sizeof wc->masks._ethernet_.hdr.ethernet__srcAddr); \
    case MFF_ETHERNET__ETHERTYPE: \
        return !wc->masks._ethernet_.hdr.ethernet__etherType; \
    case MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID: \
        return !wc->masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid; \
    case MFF_INTRINSIC_METADATA_MCAST_HASH: \
        return !wc->masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash; \
    case MFF_INTRINSIC_METADATA_LF_FIELD_LIST: \
        return !wc->masks._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list; \
    case MFF_ETHERNET__VALID: \
        return !wc->masks.valid.hdr._ethernet__valid; \
    \

/* -- Called in lib/meta-flow.c -- */
#define OVS_SET_FLOW_VALUE_CASES \
    case MFF_ETHERNET__DSTADDR: \
        memcpy(&flow->_ethernet_.hdr.ethernet__dstAddr, value->data, \
               sizeof flow->_ethernet_.hdr.ethernet__dstAddr); \
        break; \
    case MFF_ETHERNET__SRCADDR: \
        memcpy(&flow->_ethernet_.hdr.ethernet__srcAddr, value->data, \
               sizeof flow->_ethernet_.hdr.ethernet__srcAddr); \
        break; \
    case MFF_ETHERNET__ETHERTYPE: \
        flow->_ethernet_.hdr.ethernet__etherType = value->be16; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID: \
        flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid = value->u8; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_HASH: \
        flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash = value->be16; \
        break; \
    case MFF_INTRINSIC_METADATA_LF_FIELD_LIST: \
        flow->_intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list = value->be32; \
        break; \
    case MFF_ETHERNET__VALID: \
        flow->valid.hdr._ethernet__valid = value->u8; \
        break; \
    \

/* -- Called in lib/meta-flow.c -- */
#define OVS_SET_VLAUE_CASES \
    case MFF_ETHERNET__DSTADDR: \
        memset(&match->wc.masks._ethernet_.hdr.ethernet__dstAddr, 0xff, \
               sizeof match->wc.masks._ethernet_.hdr.ethernet__dstAddr); \
        memcpy(&match->flow._ethernet_.hdr.ethernet__dstAddr, value->data, \
               sizeof match->flow._ethernet_.hdr.ethernet__dstAddr); \
        break; \
    case MFF_ETHERNET__SRCADDR: \
        memset(&match->wc.masks._ethernet_.hdr.ethernet__srcAddr, 0xff, \
               sizeof match->wc.masks._ethernet_.hdr.ethernet__srcAddr); \
        memcpy(&match->flow._ethernet_.hdr.ethernet__srcAddr, value->data, \
               sizeof match->flow._ethernet_.hdr.ethernet__srcAddr); \
        break; \
    case MFF_ETHERNET__ETHERTYPE: \
        match->wc.masks._ethernet_.hdr.ethernet__etherType = OVS_BE16_MAX; \
        match->flow._ethernet_.hdr.ethernet__etherType = value->be16; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID: \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid = 0xff; \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid = value->u8; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_HASH: \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash = OVS_BE16_MAX; \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash = value->be16; \
        break; \
    case MFF_INTRINSIC_METADATA_LF_FIELD_LIST: \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list = OVS_BE32_MAX; \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list = value->be32; \
        break; \
    case MFF_ETHERNET__VALID: \
        match->wc.masks.valid.hdr._ethernet__valid = 0xff; \
        match->flow.valid.hdr._ethernet__valid = value->u8; \
        break; \
    \

/* -- Called in lib/meta-flow.c -- */
#define OVS_SET_WILD_CASES \
    case MFF_ETHERNET__DSTADDR: \
        memset(&match->flow._ethernet_.hdr.ethernet__dstAddr, 0, \
               sizeof match->flow._ethernet_.hdr.ethernet__dstAddr); \
        memset(&match->wc.masks._ethernet_.hdr.ethernet__dstAddr, 0, \
               sizeof match->wc.masks._ethernet_.hdr.ethernet__dstAddr); \
        break; \
    case MFF_ETHERNET__SRCADDR: \
        memset(&match->flow._ethernet_.hdr.ethernet__srcAddr, 0, \
               sizeof match->flow._ethernet_.hdr.ethernet__srcAddr); \
        memset(&match->wc.masks._ethernet_.hdr.ethernet__srcAddr, 0, \
               sizeof match->wc.masks._ethernet_.hdr.ethernet__srcAddr); \
        break; \
    case MFF_ETHERNET__ETHERTYPE: \
        match->flow._ethernet_.hdr.ethernet__etherType = 0; \
        match->wc.masks._ethernet_.hdr.ethernet__etherType = 0; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID: \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid = 0; \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid = 0; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_HASH: \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash = 0; \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash = 0; \
        break; \
    case MFF_INTRINSIC_METADATA_LF_FIELD_LIST: \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list = 0; \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list = 0; \
        break; \
    case MFF_ETHERNET__VALID: \
        match->flow.valid.hdr._ethernet__valid = 0; \
        match->wc.masks.valid.hdr._ethernet__valid = 0; \
        break; \
    \

/* -- Called in lib/meta-flow.c -- */
#define OVS_SET_CASES \
    case MFF_ETHERNET__DSTADDR: \
        set_masked(value->data, mask->data, \
                   (uint8_t *) &match->flow._ethernet_.hdr.ethernet__dstAddr, \
                   (uint8_t *) &match->wc.masks._ethernet_.hdr.ethernet__dstAddr, \
                   sizeof match->flow._ethernet_.hdr.ethernet__dstAddr); \
        break; \
    case MFF_ETHERNET__SRCADDR: \
        set_masked(value->data, mask->data, \
                   (uint8_t *) &match->flow._ethernet_.hdr.ethernet__srcAddr, \
                   (uint8_t *) &match->wc.masks._ethernet_.hdr.ethernet__srcAddr, \
                   sizeof match->flow._ethernet_.hdr.ethernet__srcAddr); \
        break; \
    case MFF_ETHERNET__ETHERTYPE: \
        match->flow._ethernet_.hdr.ethernet__etherType = value->be16 & mask->be16; \
        match->wc.masks._ethernet_.hdr.ethernet__etherType = mask->be16; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID: \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid = value->u8 & mask->u8; \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid = mask->u8; \
        break; \
    case MFF_INTRINSIC_METADATA_MCAST_HASH: \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash = value->be16 & mask->be16; \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash = mask->be16; \
        break; \
    case MFF_INTRINSIC_METADATA_LF_FIELD_LIST: \
        match->flow._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list = value->be32 & mask->be32; \
        match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list = mask->be32; \
        break; \
    case MFF_ETHERNET__VALID: \
        match->flow.valid.hdr._ethernet__valid = value->u8 & mask->u8; \
        match->wc.masks.valid.hdr._ethernet__valid = mask->u8; \
        break; \
    \

#endif	/* OVS_MATCH_META_FLOW_H */