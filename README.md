# Service-Locator-Pattern
A simple service locator programming design pattern written in C++. 
Can be used instead of using singleton pattern

## How To Use
- Derive custom basae class from `IService`
- Derived classes can be registereed with the locator using `Locator::RegisterService<T>()`
  - On registering the service is given a uniquq id.
- Registered Services can be retrived from the locator using `Locator::ResolveService<T>()`
  - Returns `nullptr` if there is no such service
- You can also check if a service exists with the locator using `Locator::Has<T>()`
