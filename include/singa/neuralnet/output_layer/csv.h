/************************************************************
*
* Licensed to the Apache Software Foundation (ASF) under one
* or more contributor license agreements.  See the NOTICE file
* distributed with this work for additional information
* regarding copyright ownership.  The ASF licenses this file
* to you under the Apache License, Version 2.0 (the
* "License"); you may not use this file except in compliance
* with the License.  You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing,
* software distributed under the License is distributed on an
* "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
* KIND, either express or implied.  See the License for the
* specific language governing permissions and limitations
* under the License.
*
*************************************************************/

#ifndef SINGA_NEURALNET_OUTPUT_LAYER_CSV_H_
#define SINGA_NEURALNET_OUTPUT_LAYER_CSV_H_

#include <vector>
#include "singa/neuralnet/layer.h"
#include "singa/io/store.h"

namespace singa {
/**
 * Output data (and label) for its source layer.
 */
class CSVOutputLayer : public OutputLayer {
 public:
  ~CSVOutputLayer() { delete store_; }
  void Setup(const LayerProto& proto, const vector<Layer*>& srclayers) override;
  void ComputeFeature(int flag, const vector<Layer*>& srclayers) override;

 private:
  int inst_ = 0;
  io::Store* store_;
};
}  // namespace singa
#endif  // SINGA_NEURALNET_OUTPUT_LAYER_CSV_H_
