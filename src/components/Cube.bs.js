// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Cube");

function _2dTranform(center, edge) {
  var x = center[/* x */0];
  var y = center[/* y */1];
  var z = center[/* z */2];
  var edgeH = edge * Math.sqrt(3.0) / 2.0;
  var edgeV = edge / 2.0;
  var x_index = x * edgeH - y * edgeH;
  var y_index = x * edgeV + y * edgeV + z * edge;
  return /* record */[
          /* x */x_index,
          /* y */y_index
        ];
}

function make(center, side, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              var sideAsFloat = side;
              var leftPosition = Pervasives.string_of_float(_2dTranform(center, sideAsFloat)[/* x */0] + 250.0) + "px";
              var topPosition = Pervasives.string_of_float(350.0 - _2dTranform(center, sideAsFloat)[/* y */1]) + "px";
              var offsetSyle = {
                left: leftPosition,
                top: topPosition,
                zIndex: "1"
              };
              var sideAsString = String(side) + "px";
              var faceStyle = {
                height: sideAsString,
                width: sideAsString
              };
              return React.createElement("div", {
                          className: "cube",
                          style: offsetSyle
                        }, React.createElement("div", {
                              className: "face front",
                              style: faceStyle
                            }), React.createElement("div", {
                              className: "face side",
                              style: faceStyle
                            }), React.createElement("div", {
                              className: "face top",
                              style: faceStyle
                            }));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports._2dTranform = _2dTranform;
exports.make = make;
/* component Not a pure module */
