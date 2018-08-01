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
 * File:   ofproto-dpif-xlate.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_ACTION_OFPROTO_DPIF_XLATE_H
#define	OVS_ACTION_OFPROTO_DPIF_XLATE_H 1

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_ACTION_HELPER_FUNCS \
    \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_RECIRC_UNROLL_ACTIONS_CASES \
    \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_COMPOSE_AND_XLATE_FUNCS \
    \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_DO_XLATE_ACTIONS_CASES \
    \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_COMPOSE_CALC_FIELDS_CASES \
    case MFF_ETHERNET__DSTADDR: \
        nl_msg_put_flag(ctx->odp_actions, OVS_CALC_FIELD_ATTR_ETHERNET__DSTADDR); \
        break; \
    case MFF_ETHERNET__SRCADDR: \
        nl_msg_put_flag(ctx->odp_actions, OVS_CALC_FIELD_ATTR_ETHERNET__SRCADDR); \
        break; \
    case MFF_ETHERNET__ETHERTYPE: \
        nl_msg_put_flag(ctx->odp_actions, OVS_CALC_FIELD_ATTR_ETHERNET__ETHERTYPE); \
        break; \
    \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_COMPOSE_ADD_TO_FIELD_CASES \
//    case MFF_ETHERNET__DSTADDR: \
//        break; \
//    case MFF_ETHERNET__SRCADDR: \
//        break; \
//    case MFF_ETHERNET__ETHERTYPE: \
//        compose_add_to_field_(ctx, OVS_KEY_ATTR_ETHERNET__ETHERTYPE, &value->be16, sizeof value->be16); \
//        break; \
//    \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_COMPOSE_SUB_FROM_FIELD_CASES \
//    case MFF_ETHERNET__DSTADDR: \
//        break; \
//    case MFF_ETHERNET__SRCADDR: \
//        break; \
//    case MFF_ETHERNET__ETHERTYPE: \
//        compose_sub_from_field_(ctx, OVS_KEY_ATTR_ETHERNET__ETHERTYPE, &value->be16, sizeof value->be16); \
//        break; \
//    \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_XLATE_ADD_TO_FIELD_CASES \
	union mf_value tmp; \
	case MFF_ETHERNET__DSTADDR: \
		break; \
	case MFF_ETHERNET__SRCADDR: \
		break; \
	case MFF_ETHERNET__ETHERTYPE: \
		memset(&wc->masks._ethernet_.hdr.ethernet__etherType, 0xff, sizeof value->be16); \
		apply_mask((const uint8_t *) value, (const uint8_t *) mask, \
			(uint8_t *) &tmp, sizeof value->be16); \
		tmp.be16 = htons(ntohs(flow->_ethernet_.hdr.ethernet__etherType) + ntohs(tmp.be16)); \
		apply_mask((const uint8_t *) &tmp, (const uint8_t *) mask, \
			(uint8_t *) &flow->_ethernet_.hdr.ethernet__etherType, sizeof value->be16); \
		break; \
	  \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_XLATE_SUB_FROM_FIELD_CASES \
	union mf_value tmp; \
	case MFF_ETHERNET__DSTADDR: \
		break; \
	case MFF_ETHERNET__SRCADDR: \
		break; \
	case MFF_ETHERNET__ETHERTYPE: \
		memset(&wc->masks._ethernet_.hdr.ethernet__etherType, 0xff, sizeof value->be16); \
		apply_mask((const uint8_t *) value, (const uint8_t *) mask, \
			(uint8_t *) &tmp, sizeof value->be16); \
		tmp.be16 = htons(ntohs(flow->_ethernet_.hdr.ethernet__etherType) - ntohs(tmp.be16)); \
		apply_mask((const uint8_t *) &tmp, (const uint8_t *) mask, \
			(uint8_t *) &flow->_ethernet_.hdr.ethernet__etherType, sizeof value->be16); \
		break; \
	  \

/* -- Called in ofproto/ofproto-dpif-xlate.c -- */
#define OVS_COMPOSE_ADD_REMOVE_HEADER_CASES \
    case MFF_ETHERNET__VALID: \
		nl_msg_put_flag(ctx->odp_actions, OVS_KEY_ATTR__ETHERNET_); \
        break; \
    \

#endif	/* OVS_ACTION_OFPROTO_DPIF_XLATE_H */
