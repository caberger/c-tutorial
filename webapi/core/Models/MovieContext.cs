using Microsoft.EntityFrameworkCore;

namespace core.Models
{
    public class 
        MovieContext : DbContext
    {
        public MovieContext(DbContextOptions<MovieContext> options): base(options)
        {
        }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
            //new DbInitializer(modelBuilder).Seed();
        }

        public DbSet<Movie> Movies { get; set; } = null!;
    }
}
