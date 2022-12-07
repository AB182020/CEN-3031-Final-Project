using GatorChef.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;


//The controller handles how the user interacts with the website
//Basically what happens when the user clicks on certain buttons
namespace GatorChef.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
        }

        public IActionResult MyRecipes() //When the user click the myrecipes tab display the view
        {
            return View();
        }

        public IActionResult Explore() //When the user click the explore tab display the view
        {
            return View();
        }

        public IActionResult Search()
        {
            return View();
        }

        public IActionResult AboutUs()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }


    }
}