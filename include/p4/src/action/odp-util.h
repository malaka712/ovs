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
 * File:   odp-util.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_ACTION_ODP_UTIL_H
#define	OVS_ACTION_ODP_UTIL_H 1

/* -- Called in lib/odp-util.c -- */
#define OVS_ACTION_LEN_CASES \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_FORMAT_ODP_ACTION_CASES \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_FORMAT_ODP_ACTION_CALC_FIELDS_CASES \
    case OVS_CALC_FIELD_ATTR_ETHERNET__DSTADDR: \
        ds_put_cstr(ds, "ethernet__dstAddr"); \
        break; \
    case OVS_CALC_FIELD_ATTR_ETHERNET__SRCADDR: \
        ds_put_cstr(ds, "ethernet__srcAddr"); \
        break; \
    case OVS_CALC_FIELD_ATTR_ETHERNET__ETHERTYPE: \
        ds_put_cstr(ds, "ethernet__etherType"); \
        break; \
    \

/* -- Called in lib/odp-util.c -- */
#define OVS_FORMAT_ODP_ACTION_ADD_REMOVE_HEADER_CASES \
	case OVS_KEY_ATTR__ETHERNET_: \
		ds_put_cstr(ds, "ethernet_"); \
		break; \
	\

#endif	/* OVS_ACTION_ODP_UTIL_H */
