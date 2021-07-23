#!/bin/bash

# Copyright 2020 The Nakama Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This command is a utility for downloading all .proto files required
# for making full source builds.

GOOGLE_API_COMMIT=6ae2d424245deeb34cf73c4f7aba31f1079bcc40
GOOGLE_PROTOBUF_COMMIT=6aa539bf0195f188ff86efe6fb8bfa2b676cdd46
GRPC_GATEWAY_COMMIT=bcc34ef50bda81faae5d4bbfca2e7ea8fe4700c8
NAKAMA_COMMIT=cf6d355a95ff43bb289d40e705c6fdad5a6b643e
NAKAMA_COMMON_COMMIT=7aa87d9d390f87621ff0ffde3f3f2dca7fb2a4d5

DOMAIN=https://raw.githubusercontent.com

API_URL=${DOMAIN}/heroiclabs/nakama-common/${NAKAMA_COMMON_COMMIT}/api/api.proto
APIGRPC_URL=${DOMAIN}/heroiclabs/nakama/${NAKAMA_COMMIT}/apigrpc/apigrpc.proto
GOOGLE_ANNOTATION_URL=${DOMAIN}/googleapis/googleapis/${GOOGLE_API_COMMIT}/google/api/annotations.proto
GOOGLE_EMPTY_URL=${DOMAIN}/protocolbuffers/protobuf/${GOOGLE_PROTOBUF_COMMIT}/src/google/protobuf/empty.proto
GOOGLE_HTTP_URL=${DOMAIN}/googleapis/googleapis/${GOOGLE_API_COMMIT}/google/api/http.proto
GOOGLE_PROTOBUF_ANY_URL=${DOMAIN}/protocolbuffers/protobuf/${GOOGLE_PROTOBUF_COMMIT}/src/google/protobuf/any.proto
GOOGLE_PROTOBUF_DESCRIPTOR_URL=${DOMAIN}/protocolbuffers/protobuf/${GOOGLE_PROTOBUF_COMMIT}/src/google/protobuf/descriptor.proto
GOOGLE_PROTOBUF_STRUCT_URL=${DOMAIN}/protocolbuffers/protobuf/${GOOGLE_PROTOBUF_COMMIT}/src/google/protobuf/struct.proto
GOOGLE_PROTOBUF_TIMESTAMP_URL=${DOMAIN}/protocolbuffers/protobuf/${GOOGLE_PROTOBUF_COMMIT}/src/google/protobuf/timestamp.proto
GOOGLE_PROTOBUF_WRAPPERS_URL=${DOMAIN}/protocolbuffers/protobuf/${GOOGLE_PROTOBUF_COMMIT}/src/google/protobuf/wrappers.proto
GRPC_ANNOTATION_URL=${DOMAIN}/grpc-ecosystem/grpc-gateway/${GRPC_GATEWAY_COMMIT}/protoc-gen-openapiv2/options/annotations.proto
OPENAPI_URL=${DOMAIN}/grpc-ecosystem/grpc-gateway/${GRPC_GATEWAY_COMMIT}/protoc-gen-openapiv2/options/openapiv2.proto
REALTIME_URL=${DOMAIN}/heroiclabs/nakama-common/${NAKAMA_COMMON_COMMIT}/rtapi/realtime.proto

NAKAMA_COMMON_DIR=github.com/heroiclabs/nakama-common
ROOT_DIR=proto
SWAGGER_GEN_DIR=protoc-gen-openapiv2/options
GOOGLE_API_DIR=google/api
GOOGLE_PROTOBUF_DIR=google/protobuf

rm -rf $ROOT_DIR

curl --create-dirs $API_URL -o ${ROOT_DIR}/${NAKAMA_COMMON_DIR}/api/api.proto
curl --create-dirs $APIGRPC_URL -o ${ROOT_DIR}/apigrpc.proto
curl --create-dirs $GOOGLE_ANNOTATION_URL -o ${ROOT_DIR}/${GOOGLE_API_DIR}/annotations.proto
curl --create-dirs $GOOGLE_EMPTY_URL -o ${ROOT_DIR}/${GOOGLE_PROTOBUF_DIR}/empty.proto
curl --create-dirs $GOOGLE_HTTP_URL -o ${ROOT_DIR}/${GOOGLE_API_DIR}/http.proto
curl --create-dirs $GOOGLE_PROTOBUF_ANY_URL -o ${ROOT_DIR}/${GOOGLE_PROTOBUF_DIR}/any.proto
curl --create-dirs $GOOGLE_PROTOBUF_DESCRIPTOR_URL -o ${ROOT_DIR}/${GOOGLE_PROTOBUF_DIR}/descriptor.proto
curl --create-dirs $GOOGLE_PROTOBUF_STRUCT_URL -o ${ROOT_DIR}/${GOOGLE_PROTOBUF_DIR}/struct.proto
curl --create-dirs $GOOGLE_PROTOBUF_TIMESTAMP_URL -o ${ROOT_DIR}/${GOOGLE_PROTOBUF_DIR}/timestamp.proto
curl --create-dirs $GOOGLE_PROTOBUF_WRAPPERS_URL -o ${ROOT_DIR}/${GOOGLE_PROTOBUF_DIR}/wrappers.proto
curl --create-dirs $GRPC_ANNOTATION_URL -o ${ROOT_DIR}/${SWAGGER_GEN_DIR}/annotations.proto
curl --create-dirs $OPENAPI_URL -o ${ROOT_DIR}/${SWAGGER_GEN_DIR}/openapiv2.proto
curl --create-dirs $REALTIME_URL -o ${ROOT_DIR}/${NAKAMA_COMMON_DIR}/rtapi/realtime.proto
