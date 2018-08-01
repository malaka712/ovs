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
 * File:   openvswitch.h
 * Author: mshahbaz@cs.princeton.edu
 */

#ifndef OVS_ACTION_OPENVSWITCH_H
#define	OVS_ACTION_OPENVSWITCH_H 1

/* -- Called in datapath/linux/compat/include/linux/openvswitch.h -- */
#define OVS_ACTION_ATTRS \
    \

/* -- Called in datapath/linux/compat/include/linux/openvswitch.h -- */
#define OVS_ACTION_STRUCTS \
    \

/* -- Called in datapath/linux/compat/include/linux/openvswitch.h -- */
#define OVS_CALC_FIELD_ATTRS \
    OVS_CALC_FIELD_ATTR_ETHERNET__DSTADDR, \
    OVS_CALC_FIELD_ATTR_ETHERNET__SRCADDR, \
    OVS_CALC_FIELD_ATTR_ETHERNET__ETHERTYPE, \
    OVS_CALC_FIELD_ATTR_NUMBER, \
    \

#endif	/* OVS_ACTION_OPENVSWITCH_H */