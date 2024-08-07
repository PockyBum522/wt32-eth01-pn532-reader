/*
 * Copyright 2020-2021 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

/*
 * This header file preserves symbols from pre-3.0 OpenSSL.
 * It should never be included directly, as it's already included
 * by the public sslerr.h headers, and since it will go away some
 * time in the future.
 */

#ifndef OPENSSL_SSLERR_LEGACY_H
# define OPENSSL_SSLERR_LEGACY_H
# pragma once

# include <openssl/macros.h>
# include <openssl/symhacks.h>

# ifdef  __cplusplus
extern "C" {
# endif

# ifndef OPENSSL_NO_DEPRECATED_3_0
OSSL_DEPRECATEDIN_3_0 int ERR_load_SSL_strings(void);

/* Collected _F_ macros from OpenSSL 1.1.1 */

/*
 * SSL function codes.
 */
#  define SSL_F_ADD_CLIENT_KEY_SHARE_EXT                   0
#  define SSL_F_ADD_KEY_SHARE                              0
#  define SSL_F_BYTES_TO_CIPHER_LIST                       0
#  define SSL_F_CHECK_SUITEB_CIPHER_LIST                   0
#  define SSL_F_CIPHERSUITE_CB                             0
#  define SSL_F_CONSTRUCT_CA_NAMES                         0
#  define SSL_F_CONSTRUCT_KEY_EXCHANGE_TBS                 0
#  define SSL_F_CONSTRUCT_STATEFUL_TICKET                  0
#  define SSL_F_CONSTRUCT_STATELESS_TICKET                 0
#  define SSL_F_CREATE_SYNTHETIC_MESSAGE_HASH              0
#  define SSL_F_CREATE_TICKET_PREQUEL                      0
#  define SSL_F_CT_MOVE_SCTS                               0
#  define SSL_F_CT_STRICT                                  0
#  define SSL_F_CUSTOM_EXT_ADD                             0
#  define SSL_F_CUSTOM_EXT_PARSE                           0
#  define SSL_F_D2I_SSL_SESSION                            0
#  define SSL_F_DANE_CTX_ENABLE                            0
#  define SSL_F_DANE_MTYPE_SET                             0
#  define SSL_F_DANE_TLSA_ADD                              0
#  define SSL_F_DERIVE_SECRET_KEY_AND_IV                   0
#  define SSL_F_DO_DTLS1_WRITE                             0
#  define SSL_F_DO_SSL3_WRITE                              0
#  define SSL_F_DTLS1_BUFFER_RECORD                        0
#  define SSL_F_DTLS1_CHECK_TIMEOUT_NUM                    0
#  define SSL_F_DTLS1_HEARTBEAT                            0
#  define SSL_F_DTLS1_HM_FRAGMENT_NEW                      0
#  define SSL_F_DTLS1_PREPROCESS_FRAGMENT                  0
#  define SSL_F_DTLS1_PROCESS_BUFFERED_RECORDS             0
#  define SSL_F_DTLS1_PROCESS_RECORD                       0
#  define SSL_F_DTLS1_READ_BYTES                           0
#  define SSL_F_DTLS1_READ_FAILED                          0
#  define SSL_F_DTLS1_RETRANSMIT_MESSAGE                   0
#  define SSL_F_DTLS1_WRITE_APP_DATA_BYTES                 0
#  define SSL_F_DTLS1_WRITE_BYTES                          0
#  define SSL_F_DTLSV1_LISTEN                              0
#  define SSL_F_DTLS_CONSTRUCT_CHANGE_CIPHER_SPEC          0
#  define SSL_F_DTLS_CONSTRUCT_HELLO_VERIFY_REQUEST        0
#  define SSL_F_DTLS_GET_REASSEMBLED_MESSAGE               0
#  define SSL_F_DTLS_PROCESS_HELLO_VERIFY                  0
#  define SSL_F_DTLS_RECORD_LAYER_NEW                      0
#  define SSL_F_DTLS_WAIT_FOR_DRY                          0
#  define SSL_F_EARLY_DATA_COUNT_OK                        0
#  define SSL_F_FINAL_EARLY_DATA                           0
#  define SSL_F_FINAL_EC_PT_FORMATS                        0
#  define SSL_F_FINAL_EMS                                  0
#  define SSL_F_FINAL_KEY_SHARE                            0
#  define SSL_F_FINAL_MAXFRAGMENTLEN                       0
#  define SSL_F_FINAL_RENEGOTIATE                          0
#  define SSL_F_FINAL_SERVER_NAME                          0
#  define SSL_F_FINAL_SIG_ALGS                             0
#  define SSL_F_GET_CERT_VERIFY_TBS_DATA                   0
#  define SSL_F_NSS_KEYLOG_INT                             0
#  define SSL_F_OPENSSL_INIT_SSL                           0
#  define SSL_F_OSSL_STATEM_CLIENT13_READ_TRANSITION       0
#  define SSL_F_OSSL_STATEM_CLIENT13_WRITE_TRANSITION      0
#  define SSL_F_OSSL_STATEM_CLIENT_CONSTRUCT_MESSAGE       0
#  define SSL_F_OSSL_STATEM_CLIENT_POST_PROCESS_MESSAGE    0
#  define SSL_F_OSSL_STATEM_CLIENT_PROCESS_MESSAGE         0
#  define SSL_F_OSSL_STATEM_CLIENT_READ_TRANSITION         0
#  define SSL_F_OSSL_STATEM_CLIENT_WRITE_TRANSITION        0
#  define SSL_F_OSSL_STATEM_SERVER13_READ_TRANSITION       0
#  define SSL_F_OSSL_STATEM_SERVER13_WRITE_TRANSITION      0
#  define SSL_F_OSSL_STATEM_SERVER_CONSTRUCT_MESSAGE       0
#  define SSL_F_OSSL_STATEM_SERVER_POST_PROCESS_MESSAGE    0
#  define SSL_F_OSSL_STATEM_SERVER_POST_WORK               0
#  define SSL_F_OSSL_STATEM_SERVER_PRE_WORK                0
#  define SSL_F_OSSL_STATEM_SERVER_PROCESS_MESSAGE         0
#  define SSL_F_OSSL_STATEM_SERVER_READ_TRANSITION         0
#  define SSL_F_OSSL_STATEM_SERVER_WRITE_TRANSITION        0
#  define SSL_F_PARSE_CA_NAMES                             0
#  define SSL_F_PITEM_NEW                                  0
#  define SSL_F_PQUEUE_NEW                                 0
#  define SSL_F_PROCESS_KEY_SHARE_EXT                      0
#  define SSL_F_READ_STATE_MACHINE                         0
#  define SSL_F_SET_CLIENT_CIPHERSUITE                     0
#  define SSL_F_SRP_GENERATE_CLIENT_MASTER_SECRET          0
#  define SSL_F_SRP_GENERATE_SERVER_MASTER_SECRET          0
#  define SSL_F_SRP_VERIFY_SERVER_PARAM                    0
#  define SSL_F_SSL3_CHANGE_CIPHER_STATE                   0
#  define SSL_F_SSL3_CHECK_CERT_AND_ALGORITHM              0
#  define SSL_F_SSL3_CTRL                                  0
#  define SSL_F_SSL3_CTX_CTRL                              0
#  define SSL_F_SSL3_DIGEST_CACHED_RECORDS                 0
#  define SSL_F_SSL3_DO_CHANGE_CIPHER_SPEC                 0
#  define SSL_F_SSL3_ENC                                   0
#  define SSL_F_SSL3_FINAL_FINISH_MAC                      0
#  define SSL_F_SSL3_FINISH_MAC                            0
#  define SSL_F_SSL3_GENERATE_KEY_BLOCK                    0
#  define SSL_F_SSL3_GENERATE_MASTER_SECRET                0
#  define SSL_F_SSL3_GET_RECORD                            0
#  define SSL_F_SSL3_INIT_FINISHED_MAC                     0
#  define SSL_F_SSL3_RELAY_CERT_CHAIN                     0
#  define SSL_F_SSL3_READ_BYTES                            0
#  define SSL_F_SSL3_READ_N                                0
#  define SSL_F_SSL3_SETUP_KEY_BLOCK                       0
#  define SSL_F_SSL3_SETUP_READ_BUFFER                     0
#  define SSL_F_SSL3_SETUP_WRITE_BUFFER                    0
#  define SSL_F_SSL3_WRITE_BYTES                           0
#  define SSL_F_SSL3_WRITE_PENDING                         0
#  define SSL_F_SSL_ADD_CERT_CHAIN                         0
#  define SSL_F_SSL_ADD_CERT_TO_BUF                        0
#  define SSL_F_SSL_ADD_CERT_TO_WPACKET                    0
#  define SSL_F_SSL_ADD_CLIENTHELLO_RENEGOTIATE_EXT        0
#  define SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT                 0
#  define SSL_F_SSL_ADD_CLIENTHELLO_USE_SRTP_EXT           0
#  define SSL_F_SSL_ADD_DIR_CERT_SUBJECTS_TO_STACK         0
#  define SSL_F_SSL_ADD_FILE_CERT_SUBJECTS_TO_STACK        0
#  define SSL_F_SSL_ADD_SERVERHELLO_RENEGOTIATE_EXT        0
#  define SSL_F_SSL_ADD_SERVERHELLO_TLSEXT                 0
#  define SSL_F_SSL_ADD_SERVERHELLO_USE_SRTP_EXT           0
#  define SSL_F_SSL_BAD_METHOD                             0
#  define SSL_F_SSL_BUILD_CERT_CHAIN                       0
#  define SSL_F_SSL_BYTES_TO_CIPHER_LIST                   0
#  define SSL_F_SSL_CACHE_CIPHERLIST                       0
#  define SSL_F_SSL_CERT_ADD0_CHAIN_CERT                   0
#  define SSL_F_SSL_CERT_DUP                               0
#  define SSL_F_SSL_CERT_NEW                               0
#  define SSL_F_SSL_CERT_SET0_CHAIN                        0
#  define SSL_F_SSL_CHECK_PRIVATE_KEY                      0
#  define SSL_F_SSL_CHECK_SERVERHELLO_TLSEXT               0
#  define SSL_F_SSL_CHECK_SRP_EXT_CLIENTHELLO              0
#  define SSL_F_SSL_CHECK_SRVR_ECC_CERT_AND_ALG            0
#  define SSL_F_SSL_CHOOSE_CLIENT_VERSION                  0
#  define SSL_F_SSL_CIPHER_DESCRIPTION                     0
#  define SSL_F_SSL_CIPHER_LIST_TO_BYTES                   0
#  define SSL_F_SSL_CIPHER_PROCESS_RULESTR                 0
#  define SSL_F_SSL_CIPHER_STRENGTH_SORT                   0
#  define SSL_F_SSL_CLEAR                                  0
#  define SSL_F_SSL_CLIENT_HELLO_GET1_EXTENSIONS_PRESENT   0
#  define SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD            0
#  define SSL_F_SSL_CONF_CMD                               0
#  define SSL_F_SSL_CREATE_CIPHER_LIST                     0
#  define SSL_F_SSL_CTRL                                   0
#  define SSL_F_SSL_CTX_CHECK_PRIVATE_KEY                  0
#  define SSL_F_SSL_CTX_ENABLE_CT                          0
#  define SSL_F_SSL_CTX_MAKE_PROFILES                      0
#  define SSL_F_SSL_CTX_NEW                                0
#  define SSL_F_SSL_CTX_SET_ALPN_PROTOS                    0
#  define SSL_F_SSL_CTX_SET_CIPHER_LIST                    0
#  define SSL_F_SSL_CTX_SET_CLIENT_CERT_ENGINE             0
#  define SSL_F_SSL_CTX_SET_CT_VALIDATION_CALLBACK         0
#  define SSL_F_SSL_CTX_SET_SESSION_ID_CONTEXT             0
#  define SSL_F_SSL_CTX_SET_SSL_VERSION                    0
#  define SSL_F_SSL_CTX_SET_TLSEXT_MAX_FRAGMENT_LENGTH     0
#  define SSL_F_SSL_CTX_USE_CERTIFICATE                    0
#  define SSL_F_SSL_CTX_USE_CERTIFICATE_ASN1               0
#  define SSL_F_SSL_CTX_USE_CERTIFICATE_FILE               0
#  define SSL_F_SSL_CTX_USE_PRIVATEKEY                     0
#  define SSL_F_SSL_CTX_USE_PRIVATEKEY_ASN1                0
#  define SSL_F_SSL_CTX_USE_PRIVATEKEY_FILE                0
#  define SSL_F_SSL_CTX_USE_PSK_IDENTITY_HINT              0
#  define SSL_F_SSL_CTX_USE_RSAPRIVATEKEY                  0
#  define SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_ASN1             0
#  define SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_FILE             0
#  define SSL_F_SSL_CTX_USE_SERVERINFO                     0
#  define SSL_F_SSL_CTX_USE_SERVERINFO_EX                  0
#  define SSL_F_SSL_CTX_USE_SERVERINFO_FILE                0
#  define SSL_F_SSL_DANE_DUP                               0
#  define SSL_F_SSL_DANE_ENABLE                            0
#  define SSL_F_SSL_DERIVE                                 0
#  define SSL_F_SSL_DO_CONFIG                              0
#  define SSL_F_SSL_DO_HANDSHAKE                           0
#  define SSL_F_SSL_DUP_CA_LIST                            0
#  define SSL_F_SSL_ENABLE_CT                              0
#  define SSL_F_SSL_GENERATE_PKEY_GROUP                    0
#  define SSL_F_SSL_GENERATE_SESSION_ID                    0
#  define SSL_F_SSL_GET_NEW_SESSION                        0
#  define SSL_F_SSL_GET_PREV_SESSION                       0
#  define SSL_F_SSL_GET_SERVER_CERT_INDEX                  0
#  define SSL_F_SSL_GET_SIGN_PKEY                          0
#  define SSL_F_SSL_HANDSHAKE_HASH                         0
#  define SSL_F_SSL_INIT_WBIO_BUFFER                       0
#  define SSL_F_SSL_KEY_UPDATE                             0
#  define SSL_F_SSL_LOAD_CLIENT_CA_FILE                    0
#  define SSL_F_SSL_LOG_MASTER_SECRET                      0
#  define SSL_F_SSL_LOG_RSA_CLIENT_KEY_EXCHANGE            0
#  define SSL_F_SSL_MODULE_INIT                            0
#  define SSL_F_SSL_NEW                                    0
#  define SSL_F_SSL_NEXT_PROTO_VALIDATE                    0
#  define SSL_F_SSL_PARSE_CLIENTHELLO_RENEGOTIATE_EXT      0
#  define SSL_F_SSL_PARSE_CLIENTHELLO_TLSEXT               0
#  define SSL_F_SSL_PARSE_CLIENTHELLO_USE_SRTP_EXT         0
#  define SSL_F_SSL_PARSE_SERVERHELLO_RENEGOTIATE_EXT      0
#  define SSL_F_SSL_PARSE_SERVERHELLO_TLSEXT               0
#  define SSL_F_SSL_PARSE_SERVERHELLO_USE_SRTP_EXT         0
#  define SSL_F_SSL_PEEK                                   0
#  define SSL_F_SSL_PEEK_EX                                0
#  define SSL_F_SSL_PEEK_INTERNAL                          0
#  define SSL_F_SSL_READ                                   0
#  define SSL_F_SSL_READ_EARLY_DATA                        0
#  define SSL_F_SSL_READ_EX                                0
#  define SSL_F_SSL_READ_INTERNAL                          0
#  define SSL_F_SSL_RENEGOTIATE                            0
#  define SSL_F_SSL_RENEGOTIATE_ABBREVIATED                0
#  define SSL_F_SSL_SCAN_CLIENTHELLO_TLSEXT                0
#  define SSL_F_SSL_SCAN_SERVERHELLO_TLSEXT                0
#  define SSL_F_SSL_SESSION_DUP                            0
#  define SSL_F_SSL_SESSION_NEW                            0
#  define SSL_F_SSL_SESSION_PRINT_FP                       0
#  define SSL_F_SSL_SESSION_SET1_ID                        0
#  define SSL_F_SSL_SESSION_SET1_ID_CONTEXT                0
#  define SSL_F_SSL_SET_ALPN_PROTOS                        0
#  define SSL_F_SSL_SET_CERT                               0
#  define SSL_F_SSL_SET_CERT_AND_KEY                       0
#  define SSL_F_SSL_SET_CIPHER_LIST                        0
#  define SSL_F_SSL_SET_CT_VALIDATION_CALLBACK             0
#  define SSL_F_SSL_SET_FD                                 0
#  define SSL_F_SSL_SET_PKEY                               0
#  define SSL_F_SSL_SET_RFD                                0
#  define SSL_F_SSL_SET_SESSION                            0
#  define SSL_F_SSL_SET_SESSION_ID_CONTEXT                 0
#  define SSL_F_SSL_SET_SESSION_TICKET_EXT                 0
#  define SSL_F_SSL_SET_TLSEXT_MAX_FRAGMENT_LENGTH         0
#  define SSL_F_SSL_SET_WFD                                0
#  define SSL_F_SSL_SHUTDOWN                               0
#  define SSL_F_SSL_SRP_CTX_INIT                           0
#  define SSL_F_SSL_START_ASYNC_JOB                        0
#  define SSL_F_SSL_UNDEFINED_FUNCTION                     0
#  define SSL_F_SSL_UNDEFINED_VOID_FUNCTION                0
#  define SSL_F_SSL_USE_CERTIFICATE                        0
#  define SSL_F_SSL_USE_CERTIFICATE_ASN1                   0
#  define SSL_F_SSL_USE_CERTIFICATE_FILE                   0
#  define SSL_F_SSL_USE_PRIVATEKEY                         0
#  define SSL_F_SSL_USE_PRIVATEKEY_ASN1                    0
#  define SSL_F_SSL_USE_PRIVATEKEY_FILE                    0
#  define SSL_F_SSL_USE_PSK_IDENTITY_HINT                  0
#  define SSL_F_SSL_USE_RSAPRIVATEKEY                      0
#  define SSL_F_SSL_USE_RSAPRIVATEKEY_ASN1                 0
#  define SSL_F_SSL_USE_RSAPRIVATEKEY_FILE                 0
#  define SSL_F_SSL_VALIDATE_CT                            0
#  define SSL_F_SSL_VERIFY_CERT_CHAIN                      0
#  define SSL_F_SSL_VERIFY_CLIENT_POST_HANDSHAKE           0
#  define SSL_F_SSL_WRITE                                  0
#  define SSL_F_SSL_WRITE_EARLY_DATA                       0
#  define SSL_F_SSL_WRITE_EARLY_FINISH                     0
#  define SSL_F_SSL_WRITE_EX                               0
#  define SSL_F_SSL_WRITE_INTERNAL                         0
#  define SSL_F_STATE_MACHINE                              0
#  define SSL_F_TLS12_CHECK_PEER_SIGALG                    0
#  define SSL_F_TLS12_COPY_SIGALGS                         0
#  define SSL_F_TLS13_CHANGE_CIPHER_STATE                  0
#  define SSL_F_TLS13_ENC                                  0
#  define SSL_F_TLS13_FINAL_FINISH_MAC                     0
#  define SSL_F_TLS13_GENERATE_SECRET                      0
#  define SSL_F_TLS13_HKDF_EXPAND                          0
#  define SSL_F_TLS13_RESTORE_HANDSHAKE_DIGEST_FOR_PHA     0
#  define SSL_F_TLS13_SAVE_HANDSHAKE_DIGEST_FOR_PHA        0
#  define SSL_F_TLS13_SETUP_KEY_BLOCK                      0
#  define SSL_F_TLS1_CHANGE_CIPHER_STATE                   0
#  define SSL_F_TLS1_CHECK_DUPLICATE_EXTENSIONS            0
#  define SSL_F_TLS1_ENC                                   0
#  define SSL_F_TLS1_EXPORT_KEYING_MATERIAL                0
#  define SSL_F_TLS1_GET_CURVELIST                         0
#  define SSL_F_TLS1_PRF                                   0
#  define SSL_F_TLS1_SAVE_U16                              0
#  define SSL_F_TLS1_SETUP_KEY_BLOCK                       0
#  define SSL_F_TLS1_SET_GROUPS                            0
#  define SSL_F_TLS1_SET_RAW_SIGALGS                       0
#  define SSL_F_TLS1_SET_SERVER_SIGALGS                    0
#  define SSL_F_TLS1_SET_SHARED_SIGALGS                    0
#  define SSL_F_TLS1_SET_SIGALGS                           0
#  define SSL_F_TLS_CHOOSE_SIGALG                          0
#  define SSL_F_TLS_CLIENT_KEY_EXCHANGE_POST_WORK          0
#  define SSL_F_TLS_COLLECT_EXTENSIONS                     0
#  define SSL_F_TLS_CONSTRUCT_CERTIFICATE_AUTHORITIES      0
#  define SSL_F_TLS_CONSTRUCT_CERTIFICATE_REQUEST          0
#  define SSL_F_TLS_CONSTRUCT_CERT_STATUS                  0
#  define SSL_F_TLS_CONSTRUCT_CERT_STATUS_BODY             0
#  define SSL_F_TLS_CONSTRUCT_CERT_VERIFY                  0
#  define SSL_F_TLS_CONSTRUCT_CHANGE_CIPHER_SPEC           0
#  define SSL_F_TLS_CONSTRUCT_CKE_DHE                      0
#  define SSL_F_TLS_CONSTRUCT_CKE_ECDHE                    0
#  define SSL_F_TLS_CONSTRUCT_CKE_GOST                     0
#  define SSL_F_TLS_CONSTRUCT_CKE_PSK_PREAMBLE             0
#  define SSL_F_TLS_CONSTRUCT_CKE_RSA                      0
#  define SSL_F_TLS_CONSTRUCT_CKE_SRP                      0
#  define SSL_F_TLS_CONSTRUCT_CLIENT_CERTIFICATE           0
#  define SSL_F_TLS_CONSTRUCT_CLIENT_HELLO                 0
#  define SSL_F_TLS_CONSTRUCT_CLIENT_KEY_EXCHANGE          0
#  define SSL_F_TLS_CONSTRUCT_CLIENT_VERIFY                0
#  define SSL_F_TLS_CONSTRUCT_CTOS_ALPN                    0
#  define SSL_F_TLS_CONSTRUCT_CTOS_CERTIFICATE             0
#  define SSL_F_TLS_CONSTRUCT_CTOS_COOKIE                  0
#  define SSL_F_TLS_CONSTRUCT_CTOS_EARLY_DATA              0
#  define SSL_F_TLS_CONSTRUCT_CTOS_EC_PT_FORMATS           0
#  define SSL_F_TLS_CONSTRUCT_CTOS_EMS                     0
#  define SSL_F_TLS_CONSTRUCT_CTOS_ETM                     0
#  define SSL_F_TLS_CONSTRUCT_CTOS_HELLO                   0
#  define SSL_F_TLS_CONSTRUCT_CTOS_KEY_EXCHANGE            0
#  define SSL_F_TLS_CONSTRUCT_CTOS_KEY_SHARE               0
#  define SSL_F_TLS_CONSTRUCT_CTOS_MAXFRAGMENTLEN          0
#  define SSL_F_TLS_CONSTRUCT_CTOS_NPN                     0
#  define SSL_F_TLS_CONSTRUCT_CTOS_PADDING                 0
#  define SSL_F_TLS_CONSTRUCT_CTOS_POST_HANDSHAKE_AUTH     0
#  define SSL_F_TLS_CONSTRUCT_CTOS_PSK                     0
#  define SSL_F_TLS_CONSTRUCT_CTOS_PSK_KEX_MODES           0
#  define SSL_F_TLS_CONSTRUCT_CTOS_RENEGOTIATE             0
#  define SSL_F_TLS_CONSTRUCT_CTOS_SCT                     0
#  define SSL_F_TLS_CONSTRUCT_CTOS_SERVER_NAME             0
#  define SSL_F_TLS_CONSTRUCT_CTOS_SESSION_TICKET          0
#  define SSL_F_TLS_CONSTRUCT_CTOS_SIG_ALGS                0
#  define SSL_F_TLS_CONSTRUCT_CTOS_SRP                     0
#  define SSL_F_TLS_CONSTRUCT_CTOS_STATUS_REQUEST          0
#  define SSL_F_TLS_CONSTRUCT_CTOS_SUPPORTED_GROUPS        0
#  define SSL_F_TLS_CONSTRUCT_CTOS_SUPPORTED_VERSIONS      0
#  define SSL_F_TLS_CONSTRUCT_CTOS_USE_SRTP                0
#  define SSL_F_TLS_CONSTRUCT_CTOS_VERIFY                  0
#  define SSL_F_TLS_CONSTRUCT_ENCRYPTED_EXTENSIONS         0
#  define SSL_F_TLS_CONSTRUCT_END_OF_EARLY_DATA            0
#  define SSL_F_TLS_CONSTRUCT_EXTENSIONS                   0
#  define SSL_F_TLS_CONSTRUCT_FINISHED                     0
#  define SSL_F_TLS_CONSTRUCT_HELLO_REQUEST                0
#  define SSL_F_TLS_CONSTRUCT_HELLO_RETRY_REQUEST          0
#  define SSL_F_TLS_CONSTRUCT_KEY_UPDATE                   0
#  define SSL_F_TLS_CONSTRUCT_NEW_SESSION_TICKET           0
#  define SSL_F_TLS_CONSTRUCT_NEXT_PROTO                   0
#  define SSL_F_TLS_CONSTRUCT_SERVER_CERTIFICATE           0
#  define SSL_F_TLS_CONSTRUCT_SERVER_HELLO                 0
#  define SSL_F_TLS_CONSTRUCT_SERVER_KEY_EXCHANGE          0
#  define SSL_F_TLS_CONSTRUCT_STOC_ALPN                    0
#  define SSL_F_TLS_CONSTRUCT_STOC_CERTIFICATE             0
#  define SSL_F_TLS_CONSTRUCT_STOC_COOKIE                  0
#  define SSL_F_TLS_CONSTRUCT_STOC_CRYPTOPRO_BUG           0
#  define SSL_F_TLS_CONSTRUCT_STOC_DONE                    0
#  define SSL_F_TLS_CONSTRUCT_STOC_EARLY_DATA              0
#  define SSL_F_TLS_CONSTRUCT_STOC_EARLY_DATA_INFO         0
#  define SSL_F_TLS_CONSTRUCT_STOC_EC_PT_FORMATS           0
#  define SSL_F_TLS_CONSTRUCT_STOC_EMS                     0
#  define SSL_F_TLS_CONSTRUCT_STOC_ETM                     0
#  define SSL_F_TLS_CONSTRUCT_STOC_HELLO                   0
#  define SSL_F_TLS_CONSTRUCT_STOC_KEY_EXCHANGE            0
#  define SSL_F_TLS_CONSTRUCT_STOC_KEY_SHARE               0
#  define SSL_F_TLS_CONSTRUCT_STOC_MAXFRAGMENTLEN          0
#  define SSL_F_TLS_CONSTRUCT_STOC_NEXT_PROTO_NEG          0
#  define SSL_F_TLS_CONSTRUCT_STOC_PSK                     0
#  define SSL_F_TLS_CONSTRUCT_STOC_RENEGOTIATE             0
#  define SSL_F_TLS_CONSTRUCT_STOC_SERVER_NAME             0
#  define SSL_F_TLS_CONSTRUCT_STOC_SESSION_TICKET          0
#  define SSL_F_TLS_CONSTRUCT_STOC_STATUS_REQUEST          0
#  define SSL_F_TLS_CONSTRUCT_STOC_SUPPORTED_GROUPS        0
#  define SSL_F_TLS_CONSTRUCT_STOC_SUPPORTED_VERSIONS      0
#  define SSL_F_TLS_CONSTRUCT_STOC_USE_SRTP                0
#  define SSL_F_TLS_EARLY_POST_PROCESS_CLIENT_HELLO        0
#  define SSL_F_TLS_FINISH_HANDSHAKE                       0
#  define SSL_F_TLS_GET_MESSAGE_BODY                       0
#  define SSL_F_TLS_GET_MESSAGE_HEADER                     0
#  define SSL_F_TLS_HANDLE_ALPN                            0
#  define SSL_F_TLS_HANDLE_STATUS_REQUEST                  0
#  define SSL_F_TLS_PARSE_CERTIFICATE_AUTHORITIES          0
#  define SSL_F_TLS_PARSE_CLIENTHELLO_TLSEXT               0
#  define SSL_F_TLS_PARSE_CTOS_ALPN                        0
#  define SSL_F_TLS_PARSE_CTOS_COOKIE                      0
#  define SSL_F_TLS_PARSE_CTOS_EARLY_DATA                  0
#  define SSL_F_TLS_PARSE_CTOS_EC_PT_FORMATS               0
#  define SSL_F_TLS_PARSE_CTOS_EMS                         0
#  define SSL_F_TLS_PARSE_CTOS_KEY_SHARE                   0
#  define SSL_F_TLS_PARSE_CTOS_MAXFRAGMENTLEN              0
#  define SSL_F_TLS_PARSE_CTOS_POST_HANDSHAKE_AUTH         0
#  define SSL_F_TLS_PARSE_CTOS_PSK                         0
#  define SSL_F_TLS_PARSE_CTOS_PSK_KEX_MODES               0
#  define SSL_F_TLS_PARSE_CTOS_RENEGOTIATE                 0
#  define SSL_F_TLS_PARSE_CTOS_SERVER_NAME                 0
#  define SSL_F_TLS_PARSE_CTOS_SESSION_TICKET              0
#  define SSL_F_TLS_PARSE_CTOS_SIG_ALGS                    0
#  define SSL_F_TLS_PARSE_CTOS_SIG_ALGS_CERT               0
#  define SSL_F_TLS_PARSE_CTOS_SRP                         0
#  define SSL_F_TLS_PARSE_CTOS_STATUS_REQUEST              0
#  define SSL_F_TLS_PARSE_CTOS_SUPPORTED_GROUPS            0
#  define SSL_F_TLS_PARSE_CTOS_USE_SRTP                    0
#  define SSL_F_TLS_PARSE_STOC_ALPN                        0
#  define SSL_F_TLS_PARSE_STOC_COOKIE                      0
#  define SSL_F_TLS_PARSE_STOC_EARLY_DATA                  0
#  define SSL_F_TLS_PARSE_STOC_EARLY_DATA_INFO             0
#  define SSL_F_TLS_PARSE_STOC_EC_PT_FORMATS               0
#  define SSL_F_TLS_PARSE_STOC_KEY_SHARE                   0
#  define SSL_F_TLS_PARSE_STOC_MAXFRAGMENTLEN              0
#  define SSL_F_TLS_PARSE_STOC_NPN                         0
#  define SSL_F_TLS_PARSE_STOC_PSK                         0
#  define SSL_F_TLS_PARSE_STOC_RENEGOTIATE                 0
#  define SSL_F_TLS_PARSE_STOC_SCT                         0
#  define SSL_F_TLS_PARSE_STOC_SERVER_NAME                 0
#  define SSL_F_TLS_PARSE_STOC_SESSION_TICKET              0
#  define SSL_F_TLS_PARSE_STOC_STATUS_REQUEST              0
#  define SSL_F_TLS_PARSE_STOC_SUPPORTED_VERSIONS          0
#  define SSL_F_TLS_PARSE_STOC_USE_SRTP                    0
#  define SSL_F_TLS_POST_PROCESS_CLIENT_HELLO              0
#  define SSL_F_TLS_POST_PROCESS_CLIENT_KEY_EXCHANGE       0
#  define SSL_F_TLS_PREPARE_CLIENT_CERTIFICATE             0
#  define SSL_F_TLS_PROCESS_AS_HELLO_RETRY_REQUEST         0
#  define SSL_F_TLS_PROCESS_CERTIFICATE_REQUEST            0
#  define SSL_F_TLS_PROCESS_CERT_STATUS                    0
#  define SSL_F_TLS_PROCESS_CERT_STATUS_BODY               0
#  define SSL_F_TLS_PROCESS_CERT_VERIFY                    0
#  define SSL_F_TLS_PROCESS_CHANGE_CIPHER_SPEC             0
#  define SSL_F_TLS_PROCESS_CKE_DHE                        0
#  define SSL_F_TLS_PROCESS_CKE_ECDHE                      0
#  define SSL_F_TLS_PROCESS_CKE_GOST                       0
#  define SSL_F_TLS_PROCESS_CKE_PSK_PREAMBLE               0
#  define SSL_F_TLS_PROCESS_CKE_RSA                        0
#  define SSL_F_TLS_PROCESS_CKE_SRP                        0
#  define SSL_F_TLS_PROCESS_CLIENT_CERTIFICATE             0
#  define SSL_F_TLS_PROCESS_CLIENT_HELLO                   0
#  define SSL_F_TLS_PROCESS_CLIENT_KEY_EXCHANGE            0
#  define SSL_F_TLS_PROCESS_ENCRYPTED_EXTENSIONS           0
#  define SSL_F_TLS_PROCESS_END_OF_EARLY_DATA              0
#  define SSL_F_TLS_PROCESS_FINISHED                       0
#  define SSL_F_TLS_PROCESS_HELLO_REQ                      0
#  define SSL_F_TLS_PROCESS_HELLO_RETRY_REQUEST            0
#  define SSL_F_TLS_PROCESS_INITIAL_SERVER_FLIGHT          0
#  define SSL_F_TLS_PROCESS_KEY_EXCHANGE                   0
#  define SSL_F_TLS_PROCESS_KEY_UPDATE                     0
#  define SSL_F_TLS_PROCESS_NEW_SESSION_TICKET             0
#  define SSL_F_TLS_PROCESS_NEXT_PROTO                     0
#  define SSL_F_TLS_PROCESS_SERVER_CERTIFICATE             0
#  define SSL_F_TLS_PROCESS_SERVER_DONE                    0
#  define SSL_F_TLS_PROCESS_SERVER_HELLO                   0
#  define SSL_F_TLS_PROCESS_SKE_DHE                        0
#  define SSL_F_TLS_PROCESS_SKE_ECDHE                      0
#  define SSL_F_TLS_PROCESS_SKE_PSK_PREAMBLE               0
#  define SSL_F_TLS_PROCESS_SKE_SRP                        0
#  define SSL_F_TLS_PSK_DO_BINDER                          0
#  define SSL_F_TLS_SCAN_CLIENTHELLO_TLSEXT                0
#  define SSL_F_TLS_SETUP_HANDSHAKE                        0
#  define SSL_F_USE_CERTIFICATE_CHAIN_FILE                 0
#  define SSL_F_WPACKET_INTERN_INIT_LEN                    0
#  define SSL_F_WPACKET_START_SUB_PACKET_LEN__             0
#  define SSL_F_WRITE_STATE_MACHINE                        0
# endif

# ifdef  __cplusplus
}
# endif
#endif