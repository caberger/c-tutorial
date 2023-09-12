﻿namespace core.Models
{
    internal static class DbInitializerExtension
    {
        public static IApplicationBuilder UseItToSeedSqlServer(this IApplicationBuilder app)
        {
            ArgumentNullException.ThrowIfNull(app, nameof(app));

            using var scope = app.ApplicationServices.CreateScope();
            var services = scope.ServiceProvider;
            try
            {
                var context = services.GetRequiredService<MovieContext>();
                DbInitializer.Initialize(context);
            }
            catch (Exception ex)
            {
                Console.WriteLine("failed to seed:" + ex.Message);
            }

            return app;
        }
    }
}
