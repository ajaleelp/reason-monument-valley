let component = ReasonReact.statelessComponent("Cube");

let make = _children => {
  ...component,
  render: _self =>
    <div className="cube">
      <div className="face front" />
      <div className="face side" />
      <div className="face top" />
    </div>,
};