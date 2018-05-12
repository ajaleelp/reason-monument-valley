let component = ReasonReact.statelessComponent("Cube");

type _3dCoOd = {
  x: int,
  y: int,
  z: int,
};

type triangle =
  | LeftSide
  | RightSide
  | LeftTop
  | RightTop
  | LeftFront
  | RightFront;

let leftPosition = (side: int, triangle: triangle, center: _3dCoOd) => {
  let edgeH = float_of_int(side) *. sqrt(3.0) /. 2.0;
  let x3d = float_of_int(center.x);
  let y3d = float_of_int(center.y);
  let x2d =
    switch (triangle, x3d, y3d) {
    | (LeftSide | RightSide | LeftTop, x3d, y3d) => x3d -. y3d
    | (RightFront | LeftFront | RightTop, x3d, y3d) => x3d -. y3d +. 1.0
    };
  350.0 +. x2d *. edgeH;
};

let topPosition = (side: int, triangle: triangle, center: _3dCoOd) => {
  let edgeV = float_of_int(side);
  let x3d = float_of_int(center.x);
  let y3d = float_of_int(center.y);
  let z3d = float_of_int(center.z);
  let y2d =
    switch (triangle, x3d, y3d, z3d) {
    | (LeftSide | RightFront, x3d, y3d, z3d) =>
      (x3d +. y3d +. 2.0 *. z3d) *. 0.5
    | (RightSide | LeftFront, x3d, y3d, z3d) =>
      (x3d +. y3d +. 2.0 *. z3d +. 1.0) *. 0.5
    | (LeftTop | RightTop, x3d, y3d, z3d) =>
      (x3d +. y3d +. 2.0 *. z3d +. 2.0) *. 0.5
    };
  350.0 -. y2d *. edgeV;
};

let triangleStyle = (side: int, triangle: triangle, center: _3dCoOd) => {
  let left = string_of_float(leftPosition(side, triangle, center)) ++ "px";
  let top = string_of_float(topPosition(side, triangle, center)) ++ "px";
  let borderTop = string_of_int(side / 2) ++ "px solid transparent";
  let borderBottom = string_of_int(side / 2) ++ "px solid transparent";
  let borderSize =
    string_of_float(float_of_int(side) *. 0.866) ++ "px solid";
  let borderRight =
    switch (triangle, borderSize) {
    | (LeftSide, borderSize) => borderSize ++ " green"
    | (LeftFront, borderSize) => borderSize ++ " blue"
    | (LeftTop, borderSize) => borderSize ++ " red"
    | (RightSide | RightFront | RightTop, _borderSize) => "none"
    };
  let borderLeft =
    switch (triangle, borderSize) {
    | (RightSide, borderSize) => borderSize ++ " green"
    | (RightFront, borderSize) => borderSize ++ " blue"
    | (RightTop, borderSize) => borderSize ++ " red"
    | (LeftSide | LeftFront | LeftTop, _borderSize) => "none"
    };
  let zIndexDefault = string_of_int(100 - (center.x + center.y - center.z));
  ReactDOMRe.Style.make(
    ~left,
    ~top,
    ~borderTop,
    ~borderBottom,
    ~borderRight,
    ~borderLeft,
    ~zIndex=zIndexDefault,
    (),
  );
};

let make = (~center: _3dCoOd, ~side: int, _children) => {
  ...component,
  render: _self =>
    <div className="cube">
      <div
        className="triangle"
        style=(triangleStyle(side, LeftSide, center))
      />
      <div
        className="triangle"
        style=(triangleStyle(side, RightSide, center))
      />
      <div
        className="triangle"
        style=(triangleStyle(side, LeftTop, center))
      />
      <div
        className="triangle"
        style=(triangleStyle(side, RightFront, center))
      />
      <div
        className="triangle"
        style=(triangleStyle(side, LeftFront, center))
      />
      <div
        className="triangle"
        style=(triangleStyle(side, RightTop, center))
      />
    </div>,
};