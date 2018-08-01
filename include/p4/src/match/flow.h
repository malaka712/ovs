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
 * File:   flow.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_FLOW_H
#define	OVS_MATCH_FLOW_H 1

/* -- Called in lib/flow.h -- */
#define OVS_FIELDS \
    struct _ethernet__padded_header _ethernet_; \
    struct _intrinsic_metadata_padded_header _intrinsic_metadata; \
    struct valid_padded_header valid; \
    \

/* -- Called in lib/flow.c -- */
#define OVS_MINIFLOW_EXTRACT_METADATA_DEFS \
    struct _intrinsic_metadata_padded_header _intrinsic_metadata = {0}; \
    bool is__intrinsic_metadata_header_touched = false; \
    \
    struct valid_padded_header valid = {0}; \
    \

/* -- Called in lib/flow.c -- */
#define OVS_MINIFLOW_EXTRACT \
    { \
        OVS_MINIFLOW__START \
    } \
    \

#define OVS_MINIFLOW__START \
    { \
        OVS_MINIFLOW__PARSE_ETHERNET \
    } \
    \

#define OVS_MINIFLOW__PARSE_ETHERNET \
    if (OVS_UNLIKELY(size < sizeof(struct _ethernet__header))) \
    { \
        OVS_MINIFLOW_OUT \
    } \
    \
    packet->_ethernet__ofs = ((char *) data) - l2; \
    struct _ethernet__padded_header *_ethernet_ = (struct _ethernet__padded_header *) data_pull(&data, &size, \
        sizeof(struct _ethernet__header)); \
    miniflow_push_bytes__word_aligned(mf, _ethernet_, _ethernet_, sizeof(struct _ethernet__header), \
        sizeof(struct _ethernet__padded_header) / sizeof(uint64_t)); \
	valid.hdr._ethernet__valid = 1; \
    packet->_ethernet_ = *(struct _ethernet__header *) _ethernet_; \
    packet->_ethernet__valid = 1; \
    \
    { \
        OVS_MINIFLOW_OUT \
    } \
    \

#define OVS_MINIFLOW_OUT \
    packet->payload_ofs = (char *)data - l2; \
    \
    if (OVS_LIKELY(is__intrinsic_metadata_header_touched)) \
    { \
    	miniflow_push_bytes__word_aligned(mf, _intrinsic_metadata, &_intrinsic_metadata, sizeof(struct _intrinsic_metadata_header), \
            sizeof(struct _intrinsic_metadata_padded_header) / sizeof(uint64_t)); \
    } \
    \
	miniflow_push_bytes__word_aligned(mf, valid, &valid, sizeof(struct valid_header), \
            sizeof(struct valid_padded_header) / sizeof(uint64_t)); \
    goto out; \
    \

/* -- Called in lib/flow.c -- */
#define OVS_FLOW_WC_MASK \
    WC_MASK_FIELD(wc, _ethernet_); \
	\

/* -- Called in lib/flow.c -- */
#define OVS_FLOW_WC_MAP \
    FLOWMAP_SET(map, _ethernet_); \
    FLOWMAP_SET(map, valid); \
    \

#endif	/* OVS_MATCH_FLOW_H */
