using core.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace core.Controllers
{
    [ApiController]
    [Route("movies")]
    public class MoviesController : ControllerBase
    {
        private MovieContext _dbContext;

        private readonly ILogger<MoviesController> _logger;

        public MoviesController(ILogger<MoviesController> logger, MovieContext context)
        {
            _logger = logger;
            _dbContext = context;
        }

        [HttpGet(Name = "GetMovies")]
        async public Task<ActionResult<IEnumerable<Movie>>> Get()
        {
            if (_dbContext.Movies == null)
            {
                return NotFound();
            }
            return await _dbContext.Movies.ToListAsync();
        }
    }
}