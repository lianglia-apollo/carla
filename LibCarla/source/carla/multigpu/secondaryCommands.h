// Copyright (c) 2022 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

// #include "carla/Logging.h"
#include "carla/streaming/detail/tcp/Message.h"
#include "carla/multigpu/commands.h"
#include "carla/multigpu/secondary.h"

namespace carla {
namespace multigpu {

class SecondaryCommands {
  
  using callback_type = std::function<void(MultiGPUCommand, carla::Buffer)>;

  public:
  void set_secondary(std::shared_ptr<Secondary> secondary);
  void set_callback(callback_type callback);
  void on_command(Buffer buffer);

  private:
  std::shared_ptr<Secondary>  _secondary;
  callback_type               _callback;
};

} // namespace multigpu
} // namespace carla
