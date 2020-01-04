workspace "PokerClient"
    configurations { "Debug", "Release"}
project "PokerClient"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   includedirs {"./**", "../includes"}
   libdirs {"../libs"}
   links {"dandansocket"}
   files { "**.h", "**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"