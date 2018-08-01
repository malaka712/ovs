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
 * File:   nx-match.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_NX_MATCH_H
#define	OVS_MATCH_NX_MATCH_H 1

/* -- Called in lib/nx-match.c -- */
#define OVS_MATCH_PUT_RAW \
    nxm_put(b, MFF_ETHERNET__DSTADDR, oxm, \
            &flow->_ethernet_.hdr.ethernet__dstAddr, \
            &match->wc.masks._ethernet_.hdr.ethernet__dstAddr, \
            sizeof flow->_ethernet_.hdr.ethernet__dstAddr); \
    nxm_put(b, MFF_ETHERNET__SRCADDR, oxm, \
            &flow->_ethernet_.hdr.ethernet__srcAddr, \
            &match->wc.masks._ethernet_.hdr.ethernet__srcAddr, \
            sizeof flow->_ethernet_.hdr.ethernet__srcAddr); \
    nxm_put_16m(b, MFF_ETHERNET__ETHERTYPE, oxm, \
                flow->_ethernet_.hdr.ethernet__etherType, \
                match->wc.masks._ethernet_.hdr.ethernet__etherType); \
    \
    nxm_put_8m(b, MFF_INTRINSIC_METADATA_MCAST_GRP_EGRESS_RID, oxm, \
               flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid, \
               match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid); \
    nxm_put_16m(b, MFF_INTRINSIC_METADATA_MCAST_HASH, oxm, \
                flow->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash, \
                match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash); \
    nxm_put_32m(b, MFF_INTRINSIC_METADATA_LF_FIELD_LIST, oxm, \
                flow->_intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list, \
                match->wc.masks._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list); \
    \
    nxm_put_8m(b, MFF_ETHERNET__VALID, oxm, \
               flow->valid.hdr._ethernet__valid, \
               match->wc.masks.valid.hdr._ethernet__valid); \
    \

#endif	/* OVS_MATCH_NX_MATCH_H */