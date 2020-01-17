# Totum

Totum is a simulator/engine written in C++ which tries to simulate everything!

Well probably not everything but the goal is to simulate entities like animals and plants and hopefully humans in the future, First versions will have whole entities but I plan on having entities made up of entities some time in the future.

It will (probably) have:
- Entities which are only containers of components
- A handful of components which can be attached to entites and perform different actions like reproduce, grow, die, eat and this kind of stuff
- Global systems like weather or seasons which affect all entities
- Logger and analysis tools to check how the systems evolve and tweak component and entity parameters
- Interactive console which allows dynamic manipulation of entities while the simulation is running
- ADN system which tweaks parameters through evolution and natural selection
- Performant code which can run hundreds of thousands of entities at the same time
- Full test coverage through GTest
- Automatic builds and tests through Bazel

Open to suggestions and contributions, all help is appreciated!
