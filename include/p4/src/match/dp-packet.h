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
 * File:   dp_packet.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_MATCH_DP_PACKET_H
#define	OVS_MATCH_DP_PACKET_H 1

/* -- Called in lib/dp-packet.h -- */
#define OVS_HDR_ATTRS \
    uint16_t _ethernet__ofs; \
    struct _ethernet__header _ethernet_; \
    uint8_t _ethernet__valid; \
    uint16_t payload_ofs; \
    \

/* -- Called in lib/dp-packet.h -- */
#define OVS_HDR_RESET_ATTRS \
    b->_ethernet__ofs = UINT16_MAX; \
    memset(&b->_ethernet_, 0x00, sizeof(struct _ethernet__header)); \
    b->_ethernet__valid = 0; \
    b->payload_ofs = UINT16_MAX; \
    \

/* -- Called in lib/dp-packet.h -- */
#define OVS_HDR_GET_DP_PACKET_OFS \
	static inline void * dp_packet_ethernet_(const struct dp_packet *b) { \
    	return b->_ethernet__ofs != UINT16_MAX \
    			? (char *) dp_packet_data(b) + b->_ethernet__ofs \
    			: NULL; \
    } \
	\

#endif	/* OVS_MATCH_DP_PACKET_H */
