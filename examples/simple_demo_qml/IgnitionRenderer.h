/*
 * Copyright (C) 2021 Rhys Mainwaring
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

#ifndef IGNITION_RENDERING_EXAMPLES_SIMPLE_DEMO_IGNITION_RENDERER_HH_
#define IGNITION_RENDERING_EXAMPLES_SIMPLE_DEMO_IGNITION_RENDERER_HH_

#include <QSize>

#include <ignition/rendering.hh>

/// \brief Ignition renderer class. This manages  the initialisation
/// and update of an Ignition rendering engine instance and makes the
/// rendered texture available in a shared context for an application
/// to apply to a render surface.
class IgnitionRenderer
{
public:
    /// \brief Destructor
    virtual ~IgnitionRenderer();

    /// \brief Constructor
    IgnitionRenderer();

    /// \brief Render the next frame. May be called on a render thread.
    void Render();

    /// \brief Initialise the render engine and scene. May be called on a render thread.
    void Initialise();

    /// \brief Initialise the render engine and scene. Must be called on the main thread.
    void InitialiseOnMainThread();

    /// \brief Return a boolean: true if the renderer is initialised. 
    bool Initialised() const;

    /// \brief Return the ID of the OpenGL texture.
    unsigned int TextureId() const;

    /// \brief Return the size of the texture
    QSize TextureSize() const;

private:
    /// \brief Initialise the render engine. Must be called on the main thread. 
    void InitEngine();

    /// \brief Move the camera position one step in its orbit.
    void UpdateCamera();

    /// \brief The OpenGL texture ID
    unsigned int textureId = 0;

    /// \brief The sise of the texture being rendered
    QSize textureSize = QSize(800, 600);

    /// \brief A flag to mark if the renderer has been initialised
    bool initialised = false;

    /// \brief The current camera offset in its orbit
    double cameraOffset = 0.0;

    /// \brief The camera for the example scene
    ignition::rendering::CameraPtr camera;
};

#endif // IGNITION_RENDERING_EXAMPLES_SIMPLE_DEMO_IGNITION_RENDERER_HH_
