module CppClass
  using CxxWrap
  @wrapmodule(joinpath("/home/bhattadn/Workspace/ClassTest/testrun","ClassTest"))

  function __init__()
    @initcxx
  end
end

jlClass = CppClass.derivedforJulia()

jlFn() = println("This line is printed from Julia")

CppClass.setJlFnPtr(jlClass,jlFn)

CppClass.reportName(jlClass)
