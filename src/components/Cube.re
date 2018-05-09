let component = ReasonReact.statelessComponent("Cube");

type _3dPosition = {
  x: int,
  y: int,
  z: int,
};

let make = (~center: _3dPosition, _children) => {
  ...component,
  render: _self =>
    <div className="cube">
      <div className="face front" />
      <div className="face side" />
      <div className="face top" />
    </div>,
};