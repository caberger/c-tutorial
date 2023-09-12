using core.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace core.Controllers
{
    [ApiController]
    [Route("movies")]
    public class MoviesController : ControllerBase
    {
        private readonly MovieDbContext _dbContext;
        private readonly ILogger<MoviesController> _logger;

        public MoviesController(ILogger<MoviesController> logger, MovieDbContext context)
        {
            _logger = logger;
            _dbContext = context;
        }

        [HttpGet(Name = "GetMovies")]
        async public Task<ActionResult<IEnumerable<Movie>>> Get()
        {
            return await _dbContext.Movies.ToListAsync();
        }
    }
}