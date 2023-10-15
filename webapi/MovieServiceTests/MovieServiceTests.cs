using core.Models;
using NHamcrest;
using NHamcrest.Core;
using static RestAssured.Dsl;

namespace MovieServiceTests
{
    [TestClass]
    public class MovieServiceTests
    {
        [TestMethod]
        public void WhenGetAllMoviesThenResponseHasLength2() {
            Movie[] movies = (Movie[])
                Given()
                .When()
                    .Get("http://localhost:5025/movies")
                    .Then()
                        .Log(RestAssured.Response.Logging.ResponseLogLevel.All)
                        .AssertThat()
                            .StatusCode(200)
                        .And()
                            .ContentType(Starts.With("application/json"))
                .Then()
                .DeserializeTo(typeof(Movie[]));

            Assert.AreEqual(2, movies.Length);
            Assert.AreEqual("Test Movie", movies[0].Title);
            Assert.IsNotNull(movies[1].Genre);
            Array.ForEach(movies, Movie => { Console.WriteLine("=> " + Movie.Title); });
        }
    }
}