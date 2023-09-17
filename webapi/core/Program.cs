using core.Models;
using core.Services;
using Microsoft.EntityFrameworkCore;

static void StartApplication(string[] args)
{
    var builder = WebApplication.CreateBuilder(args);
    var services = builder.Services;
    services.AddControllers();
    services.AddEndpointsApiExplorer();
    services.AddSwaggerGen();

    var ConnectString = builder.Configuration.GetConnectionString("DefaultConnection");
    services.AddDbContext<MovieDbContext>(options => options.UseNpgsql(ConnectString).UseSnakeCaseNamingConvention()); // using a postgresql database
    services.AddScoped<DbInitializer>();
    if (builder.Environment.IsDevelopment())
    {
        services.AddScoped<IGreetingService, DebugHelloGreeter>(); // demo for providing dependency injection
    }
    else
    {
        services.AddScoped<IGreetingService, ReleaseHelloGreeter>(); // demo for providing dependency injection
    }
    var app = builder.Build();

    if (app.Environment.IsDevelopment())
    {
        app.UseSwagger();
        app.UseSwaggerUI();
        app.SeedDatabaseContents();    //custom extension method to seed the initial data into the DB
    }
    else
    {
        services.AddScoped<IGreetingService, ReleaseHelloGreeter>(); // demo for providing dependency injection 
    }
    app.UseAuthorization();
    app.MapControllers();

    app.Run();
}

StartApplication(args);
