# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.1.0](https://trello.com/c/rjDSigPc) - 2019-01-??
### Added
- Entity class with a name and pointers to its components, has an update method which updates all its components
- EntityManager singleton class with pointers to all entities created, has methods for creating, getting and destroying entities
- GrowthComponent class which can grow and spread (duplicate) entities
- HungerComponent class which can get hungry, eat other entities or kill itself by starvation
- Component interface to allow for generic component manipulation