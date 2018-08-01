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
 * File:   match.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_MATCH_H
#define	OVS_MATCH_MATCH_H 1

/* -- Called in lib/match.c -- */
#define OVS_MATCH_FORMAT \
    format_bex_masked(s, "ethernet__dstAddr", \
                      (const uint8_t *) &f->_ethernet_.hdr.ethernet__dstAddr, \
                      (const uint8_t *) &wc->masks._ethernet_.hdr.ethernet__dstAddr, \
                      sizeof f->_ethernet_.hdr.ethernet__dstAddr); \
    format_bex_masked(s, "ethernet__srcAddr", \
                      (const uint8_t *) &f->_ethernet_.hdr.ethernet__srcAddr, \
                      (const uint8_t *) &wc->masks._ethernet_.hdr.ethernet__srcAddr, \
                      sizeof f->_ethernet_.hdr.ethernet__srcAddr); \
    format_be16_masked(s, "ethernet__etherType", f->_ethernet_.hdr.ethernet__etherType, \
                       wc->masks._ethernet_.hdr.ethernet__etherType); \
    \
    format_be8_masked(s, "intrinsic_metadata_mcast_grp_egress_rid", f->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid, \
                      wc->masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_grp_egress_rid); \
    format_be16_masked(s, "intrinsic_metadata_mcast_hash", f->_intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash, \
                       wc->masks._intrinsic_metadata.hdr.intrinsic_metadata_mcast_hash); \
    format_be32_masked(s, "intrinsic_metadata_lf_field_list", f->_intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list, \
                       wc->masks._intrinsic_metadata.hdr.intrinsic_metadata_lf_field_list); \
    \
    format_be8_masked(s, "ethernet__valid", f->valid.hdr._ethernet__valid, \
                      wc->masks.valid.hdr._ethernet__valid); \
    \

#endif	/* OVS_MATCH_MATCH_H */