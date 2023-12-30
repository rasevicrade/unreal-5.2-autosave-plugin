# What is it
A stupidly simple plugin to prompt user to save all changes before starting PIE/play session.
![](https://github.com/rasevicrade/unreal-5.2-autosave-plugin/blob/main/Autosave.gif)

# How to use
1. Clone/download the project
2. Inside the Plugins folder there's a PIEAutosave folder, copy this to your projects Plugins folder, if there isn't one (Plugins folder), you can create it manually as a new folder and Unreal will recognize it.
3. Start your project and open Plugins.
   
![image](https://github.com/rasevicrade/unreal-5.2-autosave-plugin/assets/20711087/153c9e16-b3c8-43db-988a-d6e3c6d06d9d)

5. Make sure PIEAutosave is active

![image](https://github.com/rasevicrade/unreal-5.2-autosave-plugin/assets/20711087/9985648a-a28f-4107-9be5-e1d8da40aa5e)

That's all.

# Why
This was built in half an hour in a rage after my Windows froze and I lost an hour of work. I didn't find a viable existing solution, so I figured might as well.

# How it works
Take a look at PieAutosave class, in StartupModule we register a listener to OnPreWorldInitialization. Within this listener we call the same method that's used by UE internally to save packages.

# Does it work with version control? 
Beats me, maybe.


