# REST API

## Model

* Map aanmaken Model
    * Klasses hierin stellen de items voor die we in een DB willen opslaan

## Controller

* Map aanmaken Data
* Repository aanmaken
    * Singleton maken
    ```cs
    builder.Services.AddSingleton<NieuwsBerichtMemoryRepository>();
    ```

### In-Memory

* Nieuw Scaffolded item aanmaken: “API Controller with read/write actions”

## Database

* Nieuw Scaffolded item aanmaken:  “API Controller with actions, using Entity Framework”
    * Model class: model
    * Data context class: waarschijnlijk nog aan te maken

* Local DataBase aanmaken met NuGet Console:
```
Add-Migration Initial -Context ContextClass
Update-Database -Context ContextClass
```