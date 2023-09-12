using core.Models;
using core.Services;
using Microsoft.AspNetCore.Mvc;

namespace core.Controllers
{
    [ApiController]
    [Route("movies")]
    public class MoviesController : ControllerBase
    {

        private readonly MovieDbContext dbContext;
        private readonly ILogger<MoviesController> logger;
        private readonly IGreetingService greeter;

        public MoviesController(ILogger<MoviesController> logger, MovieDbContext context, IGreetingService greeter)
        {
            this.logger = logger;
            this.dbContext = context;
            this.greeter = greeter;
        }
        [HttpGet(Name = "GetMovies")]
        public List<Movie> Get()
        {
            //var result = _dbContext.Movies.FromSql($"SELECT * FROM movies").ToList();
            logger.LogInformation(greeter.hello());
            var result = dbContext.Movies.ToList();
            return result;
        }
    }
}