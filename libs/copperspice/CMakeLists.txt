project(copperspice)

add_library(CsCore STATIC IMPORTED GLOBAL)
set_target_properties(CsCore PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsCore1.3.dll.a)

add_library(CsGui STATIC IMPORTED GLOBAL)
set_target_properties(CsGui PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsGui1.3.dll.a)

add_library(CsMultimedia STATIC IMPORTED GLOBAL)
set_target_properties(CsMultimedia PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsMultimedia1.3.dll.a)

add_library(CsNetwork STATIC IMPORTED GLOBAL)
set_target_properties(CsNetwork PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsNetwork1.3.dll.a)

add_library(CsOpenGL STATIC IMPORTED GLOBAL)
set_target_properties(CsOpenGL PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsOpenGL1.3.dll.a)

add_library(CsPhonon STATIC IMPORTED GLOBAL)
set_target_properties(CsPhonon PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsPhonon1.3.dll.a)

add_library(CsScript STATIC IMPORTED GLOBAL)
set_target_properties(CsScript PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsScript1.3.dll.a)

add_library(CsSql STATIC IMPORTED GLOBAL)
set_target_properties(CsSql PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsSql1.3.dll.a)

add_library(CsSvg STATIC IMPORTED GLOBAL)
set_target_properties(CsSvg PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsSvg1.3.dll.a)

add_library(CsWebKit STATIC IMPORTED GLOBAL)
set_target_properties(CsWebKit PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsWebKit1.3.dll.a)

add_library(CsXml STATIC IMPORTED GLOBAL)
set_target_properties(CsXml PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsXml1.3.dll.a)

add_library(CsXmlPatterns STATIC IMPORTED GLOBAL)
set_target_properties(CsXmlPatterns PROPERTIES IMPORTED_LOCATION
  ../libs/copperspice/libCsXmlPatterns1.3.dll.a)
  
