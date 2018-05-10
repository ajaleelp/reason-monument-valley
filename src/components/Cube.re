let component = ReasonReact.statelessComponent("Cube");

let edge = 40.0;

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

let make = (~center: _3dPosition, _children) => {
  ...component,
  render: _self => {
    let leftPosition =
      string_of_float(_2dTranform(center, 40.0).x +. 250.0) ++ "px";
    let topPosition =
      string_of_float(350.0 -. _2dTranform(center, 40.0).y) ++ "px";
    let zIndex = "1";
    let offsetSyle =
      ReactDOMRe.Style.make(
        ~left=leftPosition,
        ~top=topPosition,
        ~zIndex,
        (),
      );
    <div className="cube" style=offsetSyle>
      <div className="face front" />
      <div className="face side" />
      <div className="face top" />
    </div>;
  },
};