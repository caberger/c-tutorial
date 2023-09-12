using core.Models;
using Microsoft.EntityFrameworkCore;

namespace core.Models
{
    /*
    public class DbInitializer
    {
        private readonly ModelBuilder modelBuilder;

        public DbInitializer(ModelBuilder modelBuilder)
        {
            this.modelBuilder = modelBuilder;
            new DbInitializer(modelBuilder).Seed();
        }

        public void Seed()
        {
            modelBuilder.Entity<Movie>().HasData(
                new Movie() { Id = 1, Title = "Test Movie", Genre = "Action", ReleaseDate = DateTime.Now },
                new Movie() { Id = 2, Title = "Apollo 11", Genre = "Action", ReleaseDate = DateTime.Now }
            ) ;
        }
    }
    */
}
internal class DbInitializer
{
    internal static void Initialize(MovieContext dbContext)
    {
        ArgumentNullException.ThrowIfNull(dbContext, nameof(dbContext));
        dbContext.Database.EnsureCreated();
        if (dbContext.Movies.Any())
        {
            return;
        }

        var Movies = new Movie[]
        {
                new Movie() { Id = 1, Title = "Test Movie", Genre = "Action"},
                new Movie() { Id = 2, Title = "Apollo 11", Genre = "Action"}
        };

        foreach (var movie in Movies)
            dbContext.Movies.Add(movie);

        dbContext.SaveChanges();
    }
}
