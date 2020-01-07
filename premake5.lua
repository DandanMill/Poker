workspace "Poker"
    configurations { "Debug", "Release"}
    location  "build"

project "PokerLib"
    kind "StaticLib"
    language "C++"
    targetdir "./libs"
    includedirs {"./includes"}
    libdirs "./libs"
    files { "./PokerLib/**.cpp"}
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"



project "PokerClient"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/"
   includedirs {"./PokerClient/headers", "./includes"}
   libdirs {"./libs"}
   links {"PokerLib"}
   files { "./PokerClient/headers/**.h", "./PokerClient/src/**.cpp"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"


project "PokerServer"
    kind "ConsoleApp"
    language "C++"
    targetdir "./bin/"
    includedirs {"./PokerServer/headers/", "./includes"}
    libdirs {"./libs"}
    links {"PokerLib"}
    files { "./PokerServer/headers/**.h", "./PokerServer/src/**.cpp" }
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
    optimize "On"

