/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef _IGNITION_RENDERING_SHADERTYPE_HH_
#define _IGNITION_RENDERING_SHADERTYPE_HH_

#include <string>
#include "ignition/rendering/Util.hh"

namespace ignition
{
  namespace rendering
  {
    /// \enum ShaderType ShaderType.hh ignition/rendering/ShaderType.hh
    /// \brief Available types of shaders. Note that not all rendering-engines
    /// will be able to use each type. They will instead default to the closest
    /// alternative.
    enum IGNITION_VISIBLE ShaderType
    {
      ST_UNKNOWN  = 0, /// < Unknown or errant type
      ST_PIXEL    = 1, /// < Shader shader
      ST_VERTEX   = 2, /// < Vertex shader
      ST_NORM_OBJ = 3, /// < Object-space normal map shader
      ST_NORM_TAN = 4, /// < Tangent-space normal map shader
      ST_COUNT    = 5, /// < Total number of shader types
    };

    /// \class ShaderUtil ShaderType.hh ignition/rendering/ShaderType.hh
    /// \brief Provides supporting functions for ShaderType enum
    class IGNITION_VISIBLE ShaderUtil
    {
      /// \brief Determine if given type is valid ShaderType enum
      /// \param[in] _type Enum value to be evaluated
      public: static bool IsValid(ShaderType _type);

      /// \brief Sanitize given type. If the given value is invalid,
      /// ST_UNKNOWN will be returned, otherwise input will be returned
      /// unchanged.
      /// \return The santized shader type
      public: static ShaderType Sanitize(ShaderType _type);

      /// \brief Get human-readable name for shader type value.
      /// \return The type name
      public: static std::string GetName(ShaderType _type);

      /// \brief Get enum value by human-readable name. The given string should
      /// match watch is returned by GetName. If an invalid name is given,
      /// ST_UNKNOWN will be returned.
      /// \param[in] _name Name of the shader type to be retrieved
      /// \return The specified ShaderType enum value
      public: static ShaderType GetEnum(const std::string &_name);

      /// \brief Array of human-readable names for each ShaderType
      private: static const char *names[ST_COUNT];
    };
  }
}
#endif
