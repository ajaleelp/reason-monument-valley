let component = ReasonReact.statelessComponent("Cube");

type _3dPosition = {
  x: int,
  y: int,
  z: int,
};

type _2dPosition = {
  x: float,
  y: float,
};

let _2dTranform = (center: _3dPosition, edge) => {
  let x = float_of_int(center.x);
  let y = float_of_int(center.y);
  let z = float_of_int(center.z);
  let edgeH = edge *. sqrt(3.0) /. 2.0;
  let edgeV = edge /. 2.0;
  let x_index = x *. edgeH -. y *. edgeH;
  let y_index = x *. edgeV +. y *. edgeV +. z *. edge;
  {x: x_index, y: y_index};
};

let make = (~center: _3dPosition, ~side: int, _children) => {
  ...component,
  render: _self => {
    let sideAsFloat = float_of_int(side);
    let left =
      string_of_float(_2dTranform(center, sideAsFloat).x +. 350.0) ++ "px";
    let top =
      string_of_float(350.0 -. _2dTranform(center, sideAsFloat).y) ++ "px";
    let zIndex = string_of_int(100 - (center.x + center.y - center.z));
    let offsetSyle = ReactDOMRe.Style.make(~left, ~top, ~zIndex, ());
    let sideAsString = string_of_int(side) ++ "px";
    let faceStyle =
      ReactDOMRe.Style.make(~width=sideAsString, ~height=sideAsString, ());
    <div className="cube" style=offsetSyle>
      <div className="face front" style=faceStyle />
      <div className="face side" style=faceStyle />
      <div className="face top" style=faceStyle />
    </div>;
  },
};