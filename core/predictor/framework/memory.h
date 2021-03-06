// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "core/predictor/common/inner_common.h"
#include "core/predictor/mempool/mempool.h"

namespace baidu {
namespace paddle_serving {
namespace predictor {

class MempoolWrapper {
 public:
  MempoolWrapper() {}

  static MempoolWrapper& instance() {
    static MempoolWrapper mempool;
    return mempool;
  }

  int initialize();

  int thread_initialize();

  int thread_clear();

  void* malloc(size_t size);

  void free(void* p, size_t size);

 private:
  // im::fugue::memory::Region _region;
  THREAD_KEY_T _bspec_key;
};

}  // namespace predictor
}  // namespace paddle_serving
}  // namespace baidu
