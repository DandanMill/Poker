workspace "Poker"
    configurations { "Debug", "Release"}
    location  "build"

project "NetworkFunctionality"
    kind "StaticLib"
    language "C++"
    targetdir "./libs"
    includedirs {"./Network-Functionality/", "./includes"}
    libdirs "./libs"
    files {"./Network-Functionality/**.h", "./Network-Functionality/**.cpp"}
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"



project "PokerClient"
   kind "ConsoleApp"
   language "C++"
   targetdir "PokerClient/bin/%{cfg.buildcfg}"
   includedirs {"./PokerClient/headers", "./includes"}
   libdirs {"./libs"}
   links {"NetworkFunctionality"}
   files { "./PokerClient/headers/**.h", "./PokerClient/src/**.cpp", "./PokerServer/src/Player.cpp"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"


project "PokerServer"
    kind "ConsoleApp"
    language "C++"
    targetdir "./PokerServer/bin/%{cfg.buildcfg}"
    includedirs {"./PokerServer/headers/", "./includes"}
    libdirs {"./libs"}
    links {"NetworkFunctionality"}
    files { "./PokerServer/headers/**.h", "./PokerServer/src/**.cpp" }
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
    optimize "On"

