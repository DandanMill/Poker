workspace "Poker"
    configurations { "Debug", "Release"}
    location  "build"
project "PokerClient"
   kind "ConsoleApp"
   language "C++"
   targetdir "PokerClient/bin/%{cfg.buildcfg}"
   includedirs {"./**", "./includes"}
   libdirs {"./libs"}
   links {"dandansocket"}
   files { "./PokerClient/**.h", "./PokerClient/**.cpp" }

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
    links {"dandansocket"}
    files { "./PokerServer/headers/**.h", "./PokerServer/src/**.cpp" }
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
    optimize "On"

    project "NetworkFunctionality"
    kind "StaticLib"
    language "C++"
    targetdir "./Network-Functionality/bin/"
    includedirs {"./Network-Functionality/", "./includes"}
    libdirs "./libs"
    links {"dandansocket"}
    files {"./Network-Functionality/**.h", "./Network-Functionality/**.cpp"}
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
    optimize "On"
