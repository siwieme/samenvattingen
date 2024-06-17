# ASP.NET MVC

## Layout

* Bestand *_Layout.cshtml* bevat de overkoepelende lay-out van een webpagina
* Verwijzen naar andere Views:
    * asp-action: View in kwestie
```cshtml
<a class="navbar-brand" asp-area="" asp-controller="NewsMessages" asp-action="Index">Academie de mierennest</a>
```
```
<ul>
    <li>
        <a class="nav-link text-dark" asp-area="" asp-controller="NewsMessages" asp-action="Index">Home</a>
    </li>
    <li>
        <a class="nav-link text-dark" asp-area="" asp-controller="Home" asp-action="Session">Sessies</a>
    </li>
    <li>
        <a class="nav-link text-dark" asp-area="" asp-controller="Home" asp-action="Privacy">Privacy</a>
    </li>
</ul>
```

## Koppelen DataBase

* Zelfde als bij ASP.NET Core

## View aanpassen

* Controleren of er items aanwezig zijn in het model:
```cshtml
@if (Model == null || Model.Count<TheatherApp.Models.NewsMessage>() == 0)
{
    <div>
        <p>@ViewData["emptyMessage"]</p>
    </div>
}
```
* Meerdere items uit het model weergeven
```cshtml
<ul>
    @foreach (var item in Model)
    {
        <li>
            <h3>@Html.DisplayFor(modelItem => item.Title)</h3>
            @if (item.Id > 3)
            {
                <img src="/images/news/dummy.jpg" alt="newsmessage" width="300" height="135" />
            }
            else
            {
                <img src="/images/news/@(item.Id).jpg" alt="newsmessage" width="300" height="135" />
            }
            <p>|Toegevoegd op: @Html.DisplayFor(modelItem => item.Date)</p>
            <br />
            <p>@Html.DisplayFor(modelItem => item.Message)</p>
            <a asp-action="Details" asp-route-id="@item.Id" class="readmore">Lees meer.</a>
        </li>
    }
</ul>
```

## Errorafhandeling + Display + Required voorzien

* Modelklasse
```cs
public class NewsMessage
{
    public int? Id { get; set; }
    [Display(Name = "Nieuwsbericht titel")]
    [Required(ErrorMessage = "Titel is vereist.")]
    public string Title { get; set; }

    [Display(Name = "Bericht")]
    [Required(ErrorMessage = "Bericht mag niet leeg zijn.")]
    public string Message { get; set; }

    [Display(Name = "Datum")]
    [Required(ErrorMessage = "Datum moet ingevuld zijn.")]
    public DateTime Date { get; set; }

}
```
* View.cshtml
```cshtml
<form asp-action="Create">
    <div asp-validation-summary="ModelOnly" class="text-danger"></div>
    <div class="form-group">
        <label asp-for="Title" class="control-label"></label>
        <input asp-for="Title" class="form-control" />
        <span asp-validation-for="Title" class="text-danger"></span>
    </div>
    <div class="form-group">
        <label asp-for="Message" class="control-label"></label>
        <input asp-for="Message" class="form-control" />
        <span asp-validation-for="Message" class="text-danger"></span>
    </div>
    <div class="form-group">
        <label asp-for="Date" class="control-label"></label>
        <input asp-for="Date" class="form-control" />
        <span asp-validation-for="Date" class="text-danger"></span>
    </div>
    <div class="form-group">
        <input type="submit" value="Create" class="btn btn-primary" />
    </div>
</form>
```

## Internationalisatie

* View
```cs
@inject IViewLocalizer Localizer
@Localizer["Nieuw bericht"]
```
* Controller
```cs
private readonly TheatherAppContext _context;
private readonly IStringLocalizer<NewsMessagesController> _localizer;

public NewsMessagesController(TheatherAppContext context, IStringLocalizer<NewsMessagesController> localizer)
{
    _context = context;
    _localizer = localizer;
}
```
* Program.cs
```cs
builder.Services.AddLocalization(options => options.ResourcesPath = "Resources");
// en
builder.Services.AddControllersWithViews()
                .AddViewLocalization(LanguageViewLocationExpanderFormat.Suffix)
                .AddDataAnnotationsLocalization();

var supportedCultures = new[] { "nl", "en", "en-US", "fr", "fr-FR" };
var localizationOptions = new RequestLocalizationOptions()
    .SetDefaultCulture(supportedCultures[0])
    .AddSupportedCultures(supportedCultures)
    .AddSupportedUICultures(supportedCultures);
app.UseRequestLocalization(localizationOptions);
```
* Structuur in Resources
    * Controllers / Models / Views (map)
    * naam_Controller/Model/View.taal.resx (bestand)

## Autorisatie

### Internal

* Toevoegen aan _Layout.cshtml
```cs
<partial name="_LoginPartial"/>
```
* Instellingen in Program.cs
```cs
builder.Services.Configure<IdentityOptions>(options =>
{
    // aangepaste wachtwoordinstellingen
    options.Password.RequiredLength = 8;
    options.Password.RequiredUniqueChars = 5;

    // aangepaste lockout instellingen
    options.Lockout.MaxFailedAccessAttempts = 3;

    // uniek emailadres
    options.User.RequireUniqueEmail = true;
});
```