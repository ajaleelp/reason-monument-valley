let component = ReasonReact.statelessComponent("Cube");

let make = _children => {
  ...component,
  render: _self => {
    let a = [1, 2];
    a
    |> List.map((_x: int) => <Cube />)
    |> Array.of_list
    |> ReasonReact.arrayToElement;
  },
};