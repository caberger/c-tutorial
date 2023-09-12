using core.Models;
using Microsoft.EntityFrameworkCore;

namespace core.Models
{
    internal class DbInitializer
    {
        internal static void Initialize(MovieDbContext dbContext)
        {
            ArgumentNullException.ThrowIfNull(dbContext, nameof(dbContext));
            dbContext.Database.EnsureCreated();
            if (!dbContext.Movies.Any())
            {
                var Movies = new Movie[]
                {
                    new Movie() { Id = 1, Title = "Test Movie", Genre = "Action"},
                    new Movie() { Id = 2, Title = "Apollo 11", Genre = "Action"}
                };

                foreach (var movie in Movies)
                {
                    dbContext.Movies.Add(movie);
                }
                dbContext.SaveChanges();
            }
        }
    }
}
