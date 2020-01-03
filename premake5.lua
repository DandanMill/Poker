workspace "Poker"
   configurations { "Debug", "Release" }

project "Poker"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   includedirs {"./headers/", "./socketlib/"}
   libdirs {"./socketlib"}
   links {"dandansocket"}
   files { "./headers/**.h", "./src/**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"