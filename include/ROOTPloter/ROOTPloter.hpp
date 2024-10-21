#pragma once
#include "ROOTPloter/Histograms.hpp"
#include "ROOTPloter/Graphs.hpp"
#include <TObject.h>
#include <map>
#include <tuple>
#include <memory>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <string_view>
#include <functional>

#if __has_include(<source_location>)
  #include<source_location>
  using std::source_location;
#else
  class source_location
  {
    public:
    constexpr std::uint_least32_t line() const noexcept { return 0;}
    constexpr const char* file_name() const noexcept {return "";}
    constexpr const char* function_name() const noexcept {return "";}
    static const source_location current(){ return source_location();}
  }; 
#endif

#if defined(USE_SPDLOG)
  #include "spdlog/fwd.h"
#else
  namespace spdlog
  {
    class logger;
    class formatter;

    namespace sinks { class sink;}
    namespace level { enum level_enum : int;}
  }  // namespace spdlog
#endif

class TH1;
class TH2;
class TH3;
class TCanvas;

inline const constexpr bool BAD_PARAMETERS{false};
inline const constexpr bool BAD_NUMBER_OF_ARGUMENTS(bool a=false){ return a;};

namespace ROOTPloter
{
  class ROOTPloter
  {
    public:
      ROOTPloter(const source_location& source_loc=source_location::current());
      ROOTPloter(const std::string_view name,const source_location& source_loc=source_location::current());
      template<typename PlotType, typename... Args> void create(const PlotType& T, Args&&... args)
      {
        static_assert(std::is_convertible_v<PlotType*, Plot*>,"First argument should be one of the type defined in Graphs.hpp or Histograms.hpp");
        if constexpr(std::is_convertible_v<PlotType*, TH1*>)
        {
          static_assert(BAD_NUMBER_OF_ARGUMENTS(sizeof...(args)>=4),"TH1 needs at least 4 arguments");
          createTH1(T,std::forward<Args>(args)...);
        }
        else if constexpr(std::is_convertible_v<PlotType*, TH2*>)
        {
          static_assert(sizeof...(args)>=6,"TH2 needs at least 6 arguments");
          createTH2(T,std::forward<Args>(args)...);
        }
        else if constexpr(std::is_convertible_v<PlotType*, Plot*>)
        {
          createOthers(T,args...);
          std::cout<<"I'm other"<<std::endl;
        }
      }
      template<typename... Args> void createTH1(const TH1& th1,Args&...)
      {
        static_assert(BAD_NUMBER_OF_ARGUMENTS(),"TH1 cannot be construct with the paramaters provided ! Check https://root.cern.ch/doc/v632/classTH1.html");
      }
      void createTH1(const TH1& th1,const std::string_view name,const std::string_view title,const std::size_t& xbins,const double& xlow,const double& xup);
      void createTH2(const TH2& th2,const std::string_view name,const std::string_view title,const std::size_t& xbins,const double& xlow,const double& xup,const std::size_t& ybins,const double& ylow,const double& yup);
      //void createTH3(const TH3& th3,const std::string& name,const std::string& title,const std::size_t& xbins, double xlow, double xup, std::size_t& ybins, double ylow, double yup,std::size_t& zbins, double zlow, double zup){};
      void createOthers(const Plot& t,const std::string& y,const std::string& z,const std::size_t& i, double min, double max)
      {
        std::cout<<"ddddd"<<std::endl;
      }
      void drawAll();
      void createTCanvas(std::string_view name, std::string_view title);
      std::string name() const noexcept { return m_name; };
      virtual ~ROOTPloter();
    protected:
      spdlog::logger* log()
      {
        return m_logger;
      }
    private:
      void TObjectDeleter(TObject* obj) noexcept;
      template<typename T> using UniqueTObjectPtr = std::unique_ptr<T,std::function<void(T*)>>;
      using UniqueTH1Ptr = UniqueTObjectPtr<::TH1>;
      using UniqueTH2Ptr = UniqueTObjectPtr<::TH2>;
      
      //  Containers
      using TH1Container = std::map<std::string,UniqueTH1Ptr>;
      using TH2Container = std::map<std::string,UniqueTH2Ptr>;
      std::tuple<TH1Container,TH2Container> m_container;
      
      std::vector<UniqueTObjectPtr<TCanvas>> m_canvas;
      #if defined(USE_SPDLOG)
        const constexpr static bool m_spdlog_activated{true};
      #else
        const constexpr static bool m_spdlog_activated{false};
      #endif
      spdlog::logger* m_logger{nullptr};
      static std::size_t m_id;
      std::string m_name;
  };



}

