# Spud

Spud is a place for me to develop a renderer with defered shading and other bells and whistles using Vulkan. Currently I am working on 
writing the boilerplate Vulkan code and writing a layer that allows me to interact with the Vulkan API more quickly. In particular, managing memory 
between the gpu and cpu requires a lot of repetitive or (in this case) uninformative code. Second, I am writing a system for managing command buffer 
recording alongside multi-renderpass design. This should enable easy multi-threaded command buffer recording.

Further work will be on the rendering system: culling, LOD (such as mipmaps), direct and indirect lighting, and other fun stuff.

I also hope to experiment in the Vulkan Ray Tracing extension using much of the code written in this project.
