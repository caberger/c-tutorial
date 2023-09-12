/// Demo for Dependency Injection
namespace core.Services
{
    public interface IGreetingService
    {
        string hello();
    }

    public class ReleaseHelloGreeter : IGreetingService
    {
        public string hello()
        {
            return "hello release!";
        }
    }
    public class DebugHelloGreeter : IGreetingService
    {
        public string hello()
        {
            return "hello debug!";
        }
    }
}
