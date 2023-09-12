using core.Models;
using Microsoft.EntityFrameworkCore;

static void StartApplication(string[] args) {
    var builder = WebApplication.CreateBuilder(args);
    var services = builder.Services;
    services.AddControllers();
    services.AddEndpointsApiExplorer();
    services.AddSwaggerGen();

    var ConnectString = builder.Configuration.GetConnectionString("DefaultConnection");
    services.AddDbContext<MovieDbContext>(options => options.UseNpgsql(ConnectString));
    services.AddScoped<DbInitializer>();
    var app = builder.Build();

    if (app.Environment.IsDevelopment())
    {
        app.UseSwagger();
        app.UseSwaggerUI();
        app.SeedDatabaseContents();    //custom extension method to seed the initial data into the DB
    }
    app.UseAuthorization();
    app.MapControllers();

    app.Run();
}

StartApplication(args);