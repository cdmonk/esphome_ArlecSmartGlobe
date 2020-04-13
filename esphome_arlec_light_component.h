#include "esphome.h"

class ArlecCustomLight : public Component, public LightOutput {
 public:
 ArlecCustomLight(FloatOutput *dimmer, FloatOutput *color_temp)
  {
    dimmer_ = dimmer;
    color_temp_ = color_temp;
  }

  LightTraits get_traits() override {
    // return the traits this light supports
    auto traits = LightTraits();
    traits.set_supports_brightness(true);
    traits.set_supports_color_temperature(true);
    traits.set_min_mireds(153); // home assistant minimum 153
    traits.set_max_mireds(500); // home assistant maximum 500
    return traits;
  }

  void write_state(LightState *state) override {

    float dimmer, color_temp, color_temp_mired;

    dimmer=state->current_values.get_brightness();
    color_temp_mired=state->current_values.get_color_temperature();
    color_temp = 1-((color_temp_mired - 153) / (500 - 153)); //Calculating a value between 0 (Warm) and 1 (Cold)

    //ESP_LOGD("custom","Colour Temp request in Mireds is %f, Ouput Temp value is %f",color_temp_mired, color_temp);
    this->dimmer_->set_level(dimmer);
    this->color_temp_->set_level(color_temp);
  }

protected:
FloatOutput *dimmer_;
FloatOutput *color_temp_;

};